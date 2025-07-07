#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mock_xdev.hpp"


using ::testing::Matcher;


TEST_F(XdevTestFixture, Port1) {
    /* 
     * expect call xdev_get_link_status for port 1 twice, first time return 0, 
     * and next time return 1 
     */
    EXPECT_CALL(*_mock_xdev,
                xdev_get_link_status(1)).Times(2).WillOnce(::testing::Return(0)).WillOnce(::testing::Return(1));

    /* test if 1st call is return 0 */
    EXPECT_EQ(0, xdev_get_link_status(1));

    /* test if 2nd call is return 1 */
    EXPECT_EQ(1, xdev_get_link_status(1));
}

TEST_F(XdevTestFixture, Port2)
{
    /* 
     * expect call xdev_get_link_status for port 2, always return 1
     */
    EXPECT_CALL(*_mock_xdev,
                xdev_get_link_status(2)).WillRepeatedly(::testing::Return(1));

    /* test two times */
    EXPECT_EQ(1, xdev_get_link_status(2));
    EXPECT_EQ(1, xdev_get_link_status(2));
}
