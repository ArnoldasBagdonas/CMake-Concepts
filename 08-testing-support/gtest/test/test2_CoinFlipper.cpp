#include <tuple>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::Matcher;

#include "CoinFlipper/CoinFlipper.hpp"
#include "mock_Rnd.hpp"

struct CoinFlipperFixture: ::testing::TestWithParam<std::tuple<double, CoinFlipper::Result>>{};

INSTANTIATE_TEST_CASE_P(ValidRandomNumberGenerated, CoinFlipperFixture, ::testing::Values(
    std::make_tuple(0.0,        CoinFlipper::HEADS),
    std::make_tuple(0.25,       CoinFlipper::HEADS),
    std::make_tuple(0.49999,    CoinFlipper::HEADS),
    std::make_tuple(0.5,        CoinFlipper::TAILS),
    std::make_tuple(0.75,       CoinFlipper::TAILS),
    std::make_tuple(1.0,        CoinFlipper::TAILS))
);

TEST_P(CoinFlipperFixture, CoinFlip) {
    // 1) Create mock objects (collaborators)
    auto const & param = GetParam();
    const double randomVal = std::get<0>(param);
    const CoinFlipper::Result expectedResult = std::get<1>(param);

    // 2) Create mock objects (collaborators)
    MockRng rng;

    // 3) Specify your expectations of them

    // ON_CALL(mockObject, method(matchers))
    //     .With(multiArgumentMatcher)  // 0 or 1
    //     .WillByDefault(action);

    // EXPECT_CALL(mockObject, method(arg1Matcher, ..., argNMatcher))
    //     .With(multiArgumentMatcher)  // 0 or 1
    //     .Times(cardinality)          // 0 or 1
    //     .InSequence(sequences)       // 0+
    //     .After(expectations)         // 0+
    //     .WillOnce(action)            // 0+
    //     .WillRepeatedly(action)      // 0 or 1
    //     .RetiresOnSaturation();      // 0 or 1

    EXPECT_CALL(rng, generate(::testing::DoubleEq(0.0), ::testing::DoubleEq(1.0)))
        .Times(::testing::Exactly(1))
        .WillOnce(::testing::Return(randomVal));

    // 4) Construct object(s) under test, passing mocks
    CoinFlipper coinFlipper(&rng);

    // 5) Check output (using Google Test or some other framework)
    CoinFlipper::Result result = coinFlipper.flipCoin();
    //if ((randomVal == 0.25) || (randomVal == 1)) coinFlipper.flipCoin();  //2nd call should give an error!

    // 6) Check output (using Google Test or some other framework)
    EXPECT_EQ(expectedResult, result);

    // 7) Let gmock automatically check mock expectations were met at end of test

}
