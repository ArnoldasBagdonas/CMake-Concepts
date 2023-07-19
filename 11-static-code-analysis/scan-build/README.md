# Example Project: Clang's Static Sanitizer

Clang's static sanitizer is a powerful tool that helps developers identify potential bugs and vulnerabilities in C++ code without actually running the program. It performs static analysis on the source code, examining it for various types of defects, including null pointer dereferences, memory leaks, division by zero, and other common programming mistakes.

The static sanitizer, also known as `scan-build`, is part of the Clang compiler toolchain and uses the LLVM infrastructure to analyze the code. It generates detailed bug reports in HTML format, allowing developers to easily navigate and fix the identified issues.

The main advantages of using Clang's static sanitizer are:

1. **Early Bug Detection**: The static sanitizer allows developers to catch potential bugs before running the code, saving time and effort in the debugging process.

2. **Vulnerability Detection**: It helps identify security vulnerabilities, such as null pointer dereferences and buffer overflows, which are common sources of security exploits.

3. **Code Quality Improvement**: By pointing out issues like memory leaks, dead code, and unused variables, it helps in improving the overall code quality.

4. **Automated Bug Checking**: The static sanitizer can be integrated into the build process, enabling automated bug checking during development and continuous integration.

## Description of Test Cases

Below is a brief description of the 30 test cases covered in the example project:

1. **Null Pointer Dereference**: Accessing or modifying data through a null pointer, causing crashes or undefined behavior.

2. **Division by Zero**: Performing division with a divisor of zero, resulting in a runtime error.

3. **Memory Leak**: Dynamically allocating memory but not freeing it, leading to memory leaks.

4. **Double Free**: Attempting to free memory that has already been freed, causing memory corruption.

5. **Out-of-bounds Array Access**: Accessing array elements beyond its boundaries, leading to undefined behavior.

6. **Uninitialized Variable**: Using the value of a variable before assigning it a proper value, leading to unpredictable results.

7. **Use-after-free**: Accessing memory after it has been deallocated, resulting in undefined behavior.

8. **Incorrect Format String**: Using a format specifier that doesn't match the data type passed to the function like printf.

9. **Integer Overflow**: Performing arithmetic operations that exceed the range of integer types, leading to undefined behavior.

10. **Resource Leak - File Not Closed**: Opening files or resources without closing them, leading to resource leaks.

11. **Floating-point Comparison**: Comparing floating-point numbers using exact equality, which may lead to inaccuracies due to limited precision.

12. **Unreachable Code**: Writing code that will never be executed, often due to misplaced return statements or infinite loops.

13. **Unused Function Parameter**: Declaring function parameters that are not used within the function body.

14. **Infinite Loop**: Writing loops that have no exit condition, causing the program to run indefinitely.

15. **Missing Break in Switch Statement**: Forgetting to include the break statement in a switch block, causing multiple cases to be executed.

16. **Unchecked Return Value of Function**: Not verifying the return value of functions that can fail or return an error.

17. **Dead Store**: Assigning a value to a variable that is never used, leading to unnecessary operations.

18. **Buffer Overflow**: Writing more data to a buffer than it can hold, resulting in memory corruption.

19. **Infinite Recursion**: Writing a recursive function that has no base case, causing the recursion to continue indefinitely.

20. **Uninitialized Class Member**: Declaring a class member without initializing it, leading to unpredictable behavior.

21. **Unhandled Exception**: Not catching exceptions that can be thrown during runtime, leading to program termination.

22. **Mismatched Data Types**: Performing operations on incompatible data types without proper conversions, leading to unexpected results.

23. **Incorrect Use of dynamic_cast**: Incorrectly using dynamic_cast to cast a pointer to a base class to a pointer of a derived class.

24. **Double-locking for Mutex**: Accidentally locking a mutex twice without unlocking it in between.

25. **Incorrect Use of std::string::substr**: Using the substr function of std::string with incorrect arguments.

26. **Missing Return in Non-void Function**: Forgetting to add a return statement in a non-void function, leading to undefined behavior.

27. **Incorrect Use of std::map**: Incorrectly using std::map, resulting in unexpected behavior or incorrect data.

28. **Incorrect Use of std::lower_bound**: Incorrectly using std::lower_bound to search for an element in a sorted container.

29. **Incorrect Use of std::remove_if**: Incorrectly using std::remove_if to remove elements from a container.

30. **Incorrect Use of std::unique**: Incorrectly using std::unique to remove consecutive duplicate elements from a container.

These test cases cover a range of common programming errors that can be detected and reported by Clang's static sanitizer. Running scan-build on the example project will help you visualize and understand how these issues are identified and assist you in improving the code's quality and reliability.

##  CMakeLists.txt Explanation

It is a good practice to create a CMake target for Clang's static analyzer to simplify the build process and ensure consistent analysis across multiple subprojects. To achieve this, we can add a custom CMake target that runs scan-build for each subproject. The CMakeLists.txt file contains the necessary instructions for CMake to configure and build the project. Here's a breakdown of its contents:

- **The root CMakeLists.txt file**: sets up the main project and defines a function called add_subproject to simplify adding subprojects.

- **The `add_subproject` function**: takes the name of a subproject as a parameter and performs the following actions:

   - Adds the subdirectory for the subproject, which allows CMake to find and build the code in that subproject.
   - Creates a custom target named `${name}-scan-build` for running static code analysis on the subproject.
   - The custom target invokes the `run_scan_build.sh` script, passing the path to the subproject's source code.
   - The custom target is set to execute in the `${CMAKE_BINARY_DIR}` directory, which is the directory where CMake builds the project.
   - Adds a comment to indicate that the scan-build is being run for the subproject.
- **In the root CMakeLists.txt file, the `add_subproject` function**: is called for each subproject, `subproject1` and `subproject2`. This adds them to the build process and sets up the custom targets for static code analysis.

- **The CMakeLists.txt files in the subproject folders**: simply define the project name and create an executable target using the respective source files (main1.cpp and main2.cpp).

Overall, this CMake configuration simplifies the process of adding subprojects and incorporates static code analysis using Clang's scan-build. The custom targets allow for automated static analysis to be performed on each subproject during the build process, improving code quality and catching potential issues early in the development cycle.

## Building & Running the Example

1. Open a terminal or command prompt and navigate to the project's root directory.
2. Create a new build directory
   ```bash
   mkdir build && cd build
   ```
3. Configure and generate the build files using CMake:
   - For single-configuration generators:
   ```bash
   cmake ..
   ```
   - For multi-configuration generators:
   ```bash
   cmake -DCMAKE_BUILD_TYPE=<configuration> ..
   ```
   Replace `<configuration>` with the desired build configuration, such as "Debug" or "Release".
4. To run Clang's static analyzer for each subproject, simply execute the custom targets:
   ```bash
   cmake --build .
   ```
5. To run the built executables:
   ```bash
   ./subproject1/subproject1
   ./subproject1/subproject2

## Analyzing the Results

> **_NOTE:_** Ensure that you have Clang installed on your system. You can download and install Clang from the official LLVM website: [llvm.org](llvm.org).

To run Clang's static analyzer for each subproject, simply execute the custom targets:
```bash
cmake --build . --target subproject1-scan-build
cmake --build . --target subproject2-scan-build
```

- Clang's scan-build tool will analyze the code during the build process and generate analysis reports.

- The reports will be saved in a separate directory, typically named "YYYY-MM-DD-HH-MM-SS," created in the current working directory.

- Review the analysis reports to identify potential issues, bugs, or code quality improvements in the codebase.

- Note that static analysis tools may produce false positives or miss certain types of issues, so manual review is still necessary.

## Integration with Continuous Integration (CI)

Integrating static code analysis into your Continuous Integration (CI) pipeline is a valuable practice to ensure code quality and identify potential issues in your codebase. By incorporating static analysis tools like Clang's scan-build, you can detect bugs and vulnerabilities early in the development process. Here's how to set up static code analysis in your CI pipeline:

- **Add a dedicated step for Static Code Analysis**: Within your CI configuration, add a dedicated step to run the static code analysis. Depending on your CI system, this step can be defined as a separate job or included as part of the build process.

- **Collect and Review Analysis Results**: Ensure that the analysis results are collected and made available for further review. This may include generating reports or logs that can be accessed through your CI/CD reporting systems. Review the analysis results regularly to identify any potential issues or vulnerabilities in your code.

- **Automate Analysis on Code Changes**: Set up the CI system to trigger the static code analysis whenever code changes are committed or pull requests are submitted. This automation allows you to continuously monitor your codebase for issues and maintain code quality throughout the development process.

- **Combine with Other CI Checks**: Static code analysis is just one part of a comprehensive CI process. It's essential to combine it with other CI checks, such as unit tests, integration tests, and code reviews, to ensure a robust development workflow.

By integrating static code analysis into your CI pipeline, you can proactively identify and address potential issues, maintain code quality, and improve the overall reliability and security of your software projects. Regularly running static analysis helps catch bugs early, streamlines the development process, and ultimately leads to more efficient and higher-quality code.

## Contributing

Contributions to this repository are welcome! If you have additional examples, improvements, or bug fixes, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on contributing.

## License

This repository is licensed under the MIT License. See the LICENSE.md file for more information.
