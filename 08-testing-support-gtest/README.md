# Example Project: Google Test (gtest)

## Features of Google Test (gtest)


- **Test Fixtures**: Test fixtures allow for the creation of a common test environment and sharing setup/teardown code among multiple tests.
By defining a fixture class, a setup method can be executed before each test case, and a teardown method after each test case.
This reduces code duplication and ensures consistent test conditions.
For example, a fixture can be created for a database test that sets up a clean database instance before each test.

- **Parameterized Tests**: Parameterized tests enable running the same test logic with different input values.
Input parameters and expected results are defined, and gtest automatically generates test cases for each combination.
This is useful for testing code that should behave consistently across various inputs.
For example, a parameterized test can be created to validate a sorting algorithm with different input arrays.

- **Test Assertions**: Google Test provides a wide range of assertion macros for validating expected behavior and comparing values.
Assertions are used to check conditions and report failures if they are not met.
Some common assertions include ASSERT_TRUE, ASSERT_FALSE, EXPECT_EQ, EXPECT_NE, EXPECT_LT, EXPECT_GT, EXPECT_LE, EXPECT_GE, etc.
These assertions verify that the code under test produces the expected results.
For example, EXPECT_EQ(expected, actual) can be used to check if the actual value matches the expected value.

- **Test Organization**: Organizing tests into test suites and using descriptive test names enhances the readability and maintainability of test code.
Test suites group related tests together and define common setup/teardown behavior.
Descriptive test names make it easier to understand the purpose of each test case.
Using a consistent naming convention, such as prefixing test names with "TEST_" or "test_", makes the test code more readable and self-explanatory.

- **Mocking and Test Doubles**: Google Test provides built-in support for mocking and creating test doubles, such as stubs and mocks.
Mock classes can be created to simulate the behavior of dependencies or external components.
Mocking isolates the code under test and focuses on specific behaviors without relying on the actual implementation.
For example, a mock object can be created to simulate a network connection and test how the code handles different network scenarios.

- **Test Coverage Analysis**:Test coverage analysis measures the extent to which code is exercised by tests.
Google Test can be integrated with code coverage tools like gcov or llvm-cov to generate coverage reports.
These reports identify areas of the code that are not adequately tested and guide further testing efforts.
Aim for high test coverage to increase confidence in code correctness and decrease the likelihood of undiscovered bugs.

These comprehensive features of Google Test (gtest) provide powerful tools for creating robust and reliable test suites. Understanding and utilizing these features will help in writing effective tests and ensuring code quality.


##  CMakeLists.txt Explanation

The CMakeLists.txt file contains the necessary instructions for CMake to configure and build the project. Here's a breakdown of its contents:

- **Minimum Required Version**: Specifies the minimum version of CMake required to build the project.

- **Project Name**: Sets the name of the project.

- **C++ Standard**: Sets the C++ standard to be used for the project.

- **C++ Language Extensions**: Disables any C++ language extensions that may be enabled by default.

- **Required C++ Standard**: Ensures that the specified C++ standard is required for the project.

- **FetchContent**: Includes the FetchContent module, which allows downloading external dependencies during the build process.

- **googletest**: Declares the googletest external dependency using FetchContent. Specifies the URL from which to download it.

- **Force Shared C Runtime**: Forces the usage of the shared C runtime for googletest. This ensures compatibility with other libraries using shared runtimes.

- **MakeAvailable**: Makes the googletest dependency available by downloading it and configuring it for use in the project.

- **Enable Testing**: Enables support for testing in CMake.

- **Add Executable**: Adds an executable target named "test_binary" which will contain the test code. Specifies the source files to be compiled into the target.

- **Link Libraries**: Links the "test_binary" target with the GTest and GMock libraries. These libraries provide the testing framework functionality. Note that there are two GTest targets: GTest::gtest and GTest::gtest_main. If you need a custom main function, link against GTest::gtest only. If you do not need a custom main function, link against GTest::gtest_main to include the proper include paths and link with the static libraries implementing GTest and its main function..

- **Include Directories**: Specifies the directories to be included during the compilation of the "test_binary" target. This ensures that the necessary headers can be found.

- **GoogleTest**: Includes the GoogleTest module, which provides additional functionality for working with the testing framework.

- **Discover and Add Tests**: Discovers and adds the tests for the "test_binary" target. This allows CMake to automatically run the tests when the project is built.

## Building the Example

To perform an out-of-source build, follow these steps:

1. Create a new directory for the build process. This directory can be named `build`, `bin`, or any other descriptive name.
2. Navigate to the newly created build directory:
   ```bash
   mkdir build && cd build
   ```
3. Run the CMake command from the build directory, specifying the path to the source code directory. For example:
   ```bash
   cmake ..
   ```
4. CMake will generate the build files (e.g., Makefiles, Visual Studio solution files) in the build directory based on the CMakeLists.txt file in the source code directory.
5. Build the project using the generated build system (e.g., Makefiles):
   ```bash
   cmake --build .
   ```
6. The built binaries and artifacts will be placed in the build directory, keeping them separate from the source code.
7. From the build directory, run the resulting executable:
   ```bash
   ./test_binary
   ```
You should see the output from the "hello" program.

> **_NOTE:_** It's important to note that the build directory should be excluded from version control systems (e.g., Git) by adding it to the project's .gitignore file. This ensures that the build artifacts are not inadvertently committed to the repository.

## Running the Tests
To run the tests, follow these steps:

1. From the build directory, run the test executable:
   ```bash
   ./test_binary
   ```
   This will execute the tests and display the test results.

By following these steps, you can build and run the example program, as well as execute the tests to verify the functionality of the code.

## Getting Started

To get started with the examples, follow these steps:

1. Clone this repository: `git clone git@github.com:ArnoldasBagdonas/CMake-Concepts.git`
2. Navigate to the desired example folder: `cd cmake-concepts-examples/<example-folder>`
3. Follow the instructions provided in the example's README to build and run the example.

Make sure you have Docker installed and properly configured on your system.

## Contributing

Contributions to this repository are welcome! If you have additional examples, improvements, or bug fixes, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on contributing.

## License

This repository is licensed under the MIT License. See the LICENSE.md file for more information.
