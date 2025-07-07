# Example Project: Catch2

## Features of Catch2

- **Clear Test Structure**: Organize your tests using Catch2's expressive BDD-style macros (SCENARIO, GIVEN, WHEN, THEN, AND_WHEN, AND_THEN, AND_GIVEN) to create a clear and structured test hierarchy. This allows for easy understanding of the test flow and makes the intent of each test case explicit.

- **Test Fixture**: Use the GIVEN clause to set up the initial state or fixture for your tests. This helps create a known starting point for each test case and ensures consistent and reproducible test results.

- **Assertions**: Utilize Catch2's rich set of assertion macros (e.g., REQUIRE, CHECK) to validate expected conditions and outcomes in your tests. These assertions allow you to check the behavior of your code and ensure correctness.

- **Dependent Clauses**: Catch2 allows nesting of test clauses (THEN, AND_THEN, AND_WHEN, AND_GIVEN) to express dependencies between test steps. This helps in creating clear and readable test cases, especially when certain conditions or actions depend on previous steps.

- **Test Case Independence**: Each test case within a SCENARIO should be independent, meaning the outcome of one test case should not affect the others. This ensures reliable and isolated tests, as any dependencies or side effects are avoided.

- **Proper Use of AND_THEN**: When using multiple THEN clauses within a test case, consider using AND_THEN instead of starting a new THEN block. This improves readability and avoids redundant code.

- **Test Case Variation**: Create variations of test cases by modifying the initial state or inputs. This helps cover different scenarios and edge cases, ensuring comprehensive test coverage.

- **Test Failure Demonstration**: Intentionally introduce failing checks (CHECK) in your tests to demonstrate the behavior and output of Catch2 when a test case fails. This provides useful information for debugging and understanding the cause of the failure.

Remember, these best practices aim to improve the clarity, reliability, and comprehensiveness of your tests when using Catch2. Tailor these practices to fit your specific project requirements and consider additional practices such as organizing tests into separate files, using sections to group related tests, and providing descriptive test case and assertion messages for better documentation and readability.

##  CMakeLists.txt Explanation

The CMakeLists.txt file contains the necessary instructions for CMake to configure and build the project. Here's a breakdown of its contents:

- **Setting the minimum required version of CMake**: Specifies the minimum version of CMake required to run the project.
- **Setting the project name**: Assigns a name to the CMake project.
- **Setting the C++ standard to 14**: Sets the C++ language standard to version 14.
- **Disabling C++ extensions**: Ensures that C++ extensions are disabled.
- **Enforcing the C++ standard to be required**: Makes the C++ standard a requirement for the project.
- **Including the FetchContent module for downloading external dependencies**: Enables the use of FetchContent module for fetching external dependencies like Catch2.
- **Declaring Catch2 as an external dependency to be fetched**: Specifies Catch2 as an external dependency and provides the necessary details like the Git repository and the version.
- **Fetching and making Catch2 available for the project**: Downloads Catch2 from the specified Git repository and makes it available for the project.
- **Adding the Catch2 module path to the CMake module search path**: Includes the Catch2 extras directory in the CMake module search path for additional modules.
- **Enabling testing in CMake**: Activates testing support in CMake for the project.
- **Adding the test binary target**: Creates an executable target named "test_binary" using the specified test source file.
- **Linking the test binary with Catch2 library (including main)**: Links the "test_binary" target with the Catch2::Catch2WithMain target. Catch2::Catch2WithMain includes both the Catch2 library and the necessary main function for running the tests. This target should be used when you don't need a custom main function. By linking against Catch2::Catch2WithMain, you include the necessary include paths and static libraries for both Catch2 and its main function. This simplifies the setup when you don't need a custom main function. If you require a custom main function, you should link against Catch2::Catch2 only.
- **Including CTest for test discovery and execution**: Enables the use of CTest module for test discovery and execution.
- **Including Catch for test macros and utilities**: Provides access to Catch's test macros and utilities for writing tests.
- **Discovering and executing tests using Catch**: Uses Catch's test discovery mechanism to automatically discover and execute tests for the "test_binary" target.

This CMake file sets up a CMake project for an example project named "exampleproject" with testing support using Catch2 as the testing framework. It fetches Catch2 as an external dependency, sets up the test binary, and includes the necessary modules for testing and test discovery. The test binary is linked with Catch2, and tests are discovered and executed using Catch2's test macros and utilities.


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
