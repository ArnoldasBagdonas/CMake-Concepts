# Set the project name
project(exampleproject)

# Set the C++ standard to 14
set(CMAKE_CXX_STANDARD 14)

# Disable C++ language extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# Require the specified C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the FetchContent module for downloading external dependencies
include(FetchContent)

# Declare the googletest external dependency using FetchContent
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Force using the shared C runtime for gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make the googletest dependency available
FetchContent_MakeAvailable(googletest)

#############################################
# Unit tests
#############################################

# Enable testing support in CMake
enable_testing()

# Add an executable target named "test_binary"
add_executable(test_binary
  ${PROJECT_SOURCE_DIR}/src/CoinFlipper.cpp
  ${PROJECT_SOURCE_DIR}/test/test1_CoinFlipper.cpp
  ${PROJECT_SOURCE_DIR}/test/test2_CoinFlipper.cpp
  ${PROJECT_SOURCE_DIR}/test/test3_xdev.cpp
  ${PROJECT_SOURCE_DIR}/test/mock_xdev.cpp
)

# Link the "test_binary" target with the gtest and gmock libraries
target_link_libraries(
  test_binary
  gtest_main
  gmock
)

# Specify the include directories for the "test_binary" target
target_include_directories(test_binary
  PUBLIC ${PROJECT_SOURCE_DIR}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# Include the GoogleTest module
include(GoogleTest)

# Discover and add tests for the "test_binary" target
gtest_discover_tests(test_binary)
# or
#add_test(test_all test_binary)