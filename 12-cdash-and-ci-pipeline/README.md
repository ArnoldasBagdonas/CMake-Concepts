# Example Project: Continuous Integration with CDash, CTest, and Sanitizers using CMake

This project aims to demonstrate best practices for implementing Continuous Integration (CI) with CDash, CTest, and various sanitizers (AddressSanitizer, LeakSanitizer, ThreadSanitizer, MemorySanitizer, and UndefinedBehaviorSanitizer) in a CMake-based project. The CI pipeline ensures that code is thoroughly tested and analyzed for potential bugs and memory issues during development.

## CDash and CTest
> **_NOTE:_** To use CDash, make sure you have an account on a CDash server or set up your own CDash instance.

- **CDash** is a web-based software testing server that aggregates, analyzes, and displays the results of software testing processes.

- **CTest** is a testing tool that comes with CMake and is used to drive the tests and report the results to CDash.

- **Integrate CTest into your CMake project** by adding the following lines to your `CMakeLists.txt file`:
  ```
  include(CTest)
  enable_testing()
  ```

- **Create tests** using CTest commands like `add_test()` in your `CMakeLists.txt` file. For example:
  ```
  add_test(NAME MyTest COMMAND MyTestExecutable)
  ```

- **Run CTest** after building your project to execute the tests:
  ```
  cmake --build .
  ctest
  ```

- **Configure CDash** by setting the appropriate variables in your CMake configuration:
  ```
  cmake -DCTEST_PROJECT_NAME="MyProject" -DCTEST_NIGHTLY_START_TIME="01:00 UTC" ..
  ```
- **Or configure CDash using CTestConfig.cmake**: the `CTestConfig.cmake` file allows you to customize the behavior of CTest in your project. It is typically used to set project-specific testing configurations and variables. Here's how to use it:
  - Create a file named CTestConfig.cmake and place it in the root directory of your CMake project.
  - In CTestConfig.cmake, you can customize various testing-related settings, such as test timeouts, test arguments, test labels, etc. For example:
    ```
    # Set the name of the CTest project, which will be used in CDash.
    set(CTEST_PROJECT_NAME "MyTestProjectName")

    # Set the nightly start time for test scheduling. The tests will start at 01:00:00 UTC.
    set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

    # Set the method for dropping test results to CDash. In this case, HTTPS will be used.
    set(CTEST_DROP_METHOD "https")

    # Set the CDash server where test results will be submitted.
    set(CTEST_DROP_SITE "my.cdash.org")

    # Set the location on the CDash server where test results will be submitted.
    set(CTEST_DROP_LOCATION "/submit.php?project=MyTestProjectLocation")

    # Enable CDash site support. Set this to TRUE to enable CDash integration.
    set(CTEST_DROP_SITE_CDASH TRUE)

    # Set the maximum time (in seconds) allowed for each test to run before it's considered as failed.
    set(CTEST_TEST_TIMEOUT 120)

    # Set custom arguments that will be passed to the test command.
    # In this case, we are setting "--verbose" to enable verbose test output.
    set(CTEST_CUSTOM_TESTS_ARGS "--verbose")
    ```
  - You can also include additional configuration files or scripts from CTestConfig.cmake if you have more complex setups.

- **After running ctest, you can visit your CDash dashboard** to view the test results and other statistics.

## CI Pipeline
- A Continuous Integration (CI) pipeline automates the building, testing, and deployment of your software whenever changes are made to the repository.

- Set up a CI server (e.g., Jenkins, Travis CI, GitLab CI/CD) and configure it to trigger builds on every push or pull request.

- In your CI pipeline, you'll typically want to perform the following steps:

  - Clone the repository: Fetch the latest code from the repository.

  - Install dependencies: Ensure that the required build tools and libraries are installed.

  - Build the project: Use CMake to generate the build files and compile the code.

  - Run tests: Execute the tests using CTest and gather the test results.

  - Optionally, deploy the software: If the tests pass successfully, you may deploy the software to a staging or production environment.

## ci_pipeline.cmake Explanation
The `ci_pipeline.cmake` script serves as a custom Continuous Integration (CI) pipeline for your CMake-based project. It automates the process of building, testing, and submitting test results to CDash, utilizing CTest and various sanitizers (AddressSanitizer, LeakSanitizer, ThreadSanitizer, MemorySanitizer, and UndefinedBehaviorSanitizer). This script supports the following options for configuration:

- **ENABLE_COVERAGE (ON/OFF)**: Enable or disable code coverage reporting.By setting this option to "ON," the CI pipeline will generate code coverage reports using the specified coverage tool. If set to "OFF," code coverage reporting will be disabled.

- **BUILD_NAME**: Specify the build configuration for the CI pipeline. Choose from various build configurations, including "Debug," "Release," "MinSizeRel," "RelWithDebInfo," "Coverage," "AddressSanitizer," "LeakSanitizer," "ThreadSanitizer," "MemorySanitizer," "UndefinedBehaviorSanitizer," or "Valgrind." This option determines the build type and enables specific sanitizers if applicable.

The ci_pipeline.cmake script incorporates these options to tailor the build and testing process according to your project's requirements. By providing the desired build configuration and enabling code coverage or sanitizers, you can effectively ensure the reliability, performance, and security of your CMake project in the CI pipeline.

##  CMakeLists.txt Explanation
The `CMakeLists.txt` file serves as the primary configuration file for the CMake-based project. It defines the build settings, includes dependencies, and configures the CI pipeline for the project. Below is a breakdown of its functionality:

- **Project Setup and Dependencies**:

  - The `project()` command sets up the project name and language requirements.
  - GoogleTest is included as an external dependency using `FetchContent`.

- **Build Configuration and Sanitizers**:

  - The `CMAKE_CXX_STANDARD` sets the required C++ standard to C++14.
  - The `CMAKE_CXX_EXTENSIONS` and `CMAKE_CXX_STANDARD_REQUIRED` options are set to control C++ standard extensions.
  - The `BUILD_NAME` option is used to specify the build configuration, which defaults to the CMake build type.
  - When the compiler is GNU or Clang, and the build type is "Debug," the script enables various sanitizers (AddressSanitizer, LeakSanitizer, ThreadSanitizer, MemorySanitizer, and UndefinedBehaviorSanitizer) based on the `BUILD_NAME`.

- **CDash Configuration and Submission**:

  - The script configures CDash to accept test results and code coverage data by creating a custom target, `submit_to_cdash`.
  - The `submit_to_cdash` target uses `CMAKE_CTEST_COMMAND` to execute the `ci_pipeline.cmake` script with appropriate arguments like `BUILD_NAME` and `ENABLE_COVERAGE`.

- **Testing Configuration and Execution**:
  - CTest is included using `include(CTest)` to enable testing in the project.
  - The `enable_testing()` command sets up the project to support testing.
  - The `add_executable()` command creates the `test_binary` executable and compiles the test source files.
  - GoogleTest is linked to the `test_binary` using `target_link_libraries()`.
  - The `target_include_directories()` command includes necessary directories for compiling the `test_binary`.
  - `gtest_discover_tests()` discovers and runs the tests using GoogleTest's built-in test discovery mechanism.

The `CMakeLists.txt` file ensures that the project is properly configured, the tests are executed, and the results are submitted to CDash for continuous integration and reporting.


## Building & Running the Example

To perform an out-of-source build, follow these steps:

1. Create a new directory for the build process. This directory can be named `build`, `bin`, or any other descriptive name.
2. Navigate to the newly created build directory:
   ```bash
   mkdir build && cd build
   ```
3. Run the CMake command from the build directory, specifying the path to the source code directory. For example:
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Release /path/to/source/code
   ```
   Replace /path/to/source/code with the actual path to your source code directory.
The -DCMAKE_BUILD_TYPE=Release flag specifies the build type as Release, which enables optimizations and produces a release-ready build.
4. CMake will generate the build files (e.g., Makefiles, Visual Studio solution files) in the build directory based on the CMakeLists.txt file in the source code directory.
5. Build the project using the generated build system (e.g., Makefiles):
   ```bash
   cmake --build .
   ```
6. The built binaries and artifacts will be placed in the build directory, keeping them separate from the source code.
7. From the build directory, run the resulting executable:
   ```bash
   ./allDefects
   ```
You should see the output from the "allDefects" program.

> **_NOTE:_** It's important to note that the build directory should be excluded from version control systems (e.g., Git) by adding it to the project's .gitignore file. This ensures that the build artifacts are not inadvertently committed to the repository.

## Custom Pipeline Run
The `ctest -S` command allows you to run a custom pipeline by specifying a CMake script that contains instructions for building, testing, and other tasks. Here's how to create and use a custom pipeline run:
- Create a file named `ci_pipeline.cmake` in the root directory of your project. In `ci_pipeline.cmake`, you can include the following types of instructions: 
  - Set up the build environment, e.g. specifying the C++ compiler, build type, and other necessary configurations.
  - Fetch external dependencies and ensure they are available for the build.
  - Generate build files using CMake.
  - Build your project
  - Run tests using ctest.
  - Optionally, include commands for deploying the software or generating coverage reports.
- To execute the custom pipeline, use the `ctest -S` command:
  ```
  ctest -S ci_pipeline.cmake -DENABLE_COVERAGE=ON -DBUILD_NAME=<configuration>
  ```
  Replace `<configuration>` with the desired build configuration, such as "Debug", "Release", "MinSizeRel", "RelWithDebInfo", "Coverage", "AddressSanitizer", "LeakSanitizer", "ThreadSanitizer", "MemorySanitizer",
  "UndefinedBehaviorSanitizer" or "Valgrind".


## Contributing

Contributions to this repository are welcome! If you have additional examples, improvements, or bug fixes, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on contributing.

## License

This repository is licensed under the MIT License. See the LICENSE.md file for more information.
