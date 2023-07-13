#include "mock_xdev.hpp"

/* make the class static member accessible to other function */
std::unique_ptr<XdevMock>  XdevTestFixture::_mock_xdev;


// C++ code implements C mock functions:

extern "C" int xdev_get_link_status(int port);

int xdev_get_link_status(int port)
{
    int retval;

    /* invoke GMock function through classs static member */
    retval = XdevTestFixture::_mock_xdev->xdev_get_link_status(port);

    return retval;
}
