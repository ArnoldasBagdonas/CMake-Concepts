#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::Matcher;

#include "CoinFlipper/CoinFlipper.hpp"
#include "mock_Rnd.hpp"

TEST(CoinFlipperFixture, ShouldReturnHeadsIfRandValueIsLessThanProbability) {
    // 1) Create mock objects (collaborators)
    MockRng rng;

    // 2) Specify your expectations of them

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
        .WillOnce(::testing::Return(0.25));

    // 3) Construct object(s) under test, passing mocks
    CoinFlipper coinFlipper(&rng);

    // 4) Run code under test
    CoinFlipper::Result result = coinFlipper.flipCoin();
    //CoinFlipper::Result result2 = coinFlipper.flipCoin(); //2nd call should give an error!

    // 5) Check output (using Google Test or some other framework)
    EXPECT_EQ(CoinFlipper::HEADS, result);

    // 6) Let gmock automatically check mock expectations were met at end of test
}

TEST(CoinFlipperFixture, InvalidRngReturnValue) {
     GTEST_FLAG_SET(death_test_style, "threadsafe");
    // This test is run in the "threadsafe" style:

    MockRng rng;

    ON_CALL(rng, generate(::testing::_, ::testing::_))
        .WillByDefault(::testing::Return(-1));
        //.WillByDefault(::testing::Return(0.5)); //valid Rng return value should give an test error!

    CoinFlipper coinFlipper(&rng);

    ASSERT_DEATH({
        CoinFlipper::Result result = coinFlipper.flipCoin();
    }, "");
}
