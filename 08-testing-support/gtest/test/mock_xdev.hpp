#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

// include the prototype of mock function (C function)

#include "xdev/xdev.h"

// GMock class to define the mock API
class XdevMock
{
public:
    virtual ~XdevMock() {}

    /* mock api */
    MOCK_METHOD1(xdev_get_link_status, int(int));
};

// GTest test fixture and unit test class
class XdevTestFixture : public ::testing::Test
{
public:
    XdevTestFixture()
    {
        /* allocatet the mock object */
        _mock_xdev.reset(new ::testing::NiceMock<XdevMock>());
    }

    ~XdevTestFixture()
    {
        /* free the mock object */
        _mock_xdev.reset();
    }
    
    static std::unique_ptr<XdevMock>  _mock_xdev;

    virtual void SetUp() {}
    virtual void TearDown() {}
};