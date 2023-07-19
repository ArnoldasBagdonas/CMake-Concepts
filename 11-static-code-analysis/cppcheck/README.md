# Example Project: Cppcheck 

Cppcheck is an open-source static code analysis tool designed for C and C++ codebases. Its main purpose is to help developers identify potential bugs, errors, and security vulnerabilities in their source code. By analyzing the code without executing it, cppcheck can catch various issues that might otherwise go unnoticed during regular compilation or testing.

Here are some key features of cppcheck:

- **Static Analysis**: cppcheck performs static code analysis, which means it examines the source code without actually executing it. It scans the code for common programming errors, potential bugs, and coding style issues.

- **Wide Range of Checks**: cppcheck includes a broad set of checks that cover various aspects of C and C++ programming, including memory management, undefined behavior, resource leaks, and more.

- **Customizable Checks**: Developers can configure the tool to enable or disable specific checks depending on their project's requirements.

- **Integration with Build Systems**: cppcheck can be integrated into various build systems and development environments, allowing developers to incorporate it seamlessly into their workflow.

- **User-Friendly Output**: The tool provides clear and concise reports, making it easier for developers to understand and fix the identified issues.

- **Command-Line Interface and GUI**: cppcheck can be used through its command-line interface (CLI) for automation and scripting purposes. Additionally, it offers a graphical user interface (GUI) for more interactive usage.

- **Regular Updates**: The cppcheck project is open-source and actively maintained, meaning that it receives updates and improvements to keep up with the evolving best practices and language standards.

- **Cross-Platform Support**: cppcheck is designed to work on various platforms, including Windows, macOS, and various Unix-like operating systems.

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

The CMakeLists.txt files in this project demonstrate how to integrate cppcheck into a CMake-based project with subprojects.

In the root CMakeLists.txt:

- It sets the minimum required CMake version to 3.5 and defines the project name as "exampleproject"

- It searches for the cppcheck executable using `find_program`.

- If cppcheck is found, it sets the `CMAKE_EXPORT_COMPILE_COMMANDS` variable to generate `compile_commands.json`, which cppcheck will use for analysis.

- It creates a custom target named `run_cppcheck` that executes cppcheck on all subprojects using the `--project` option and the generated `compile_commands.json` file.

- If cppcheck is not found, it issues a warning.

- It includes the subprojects (subproject1 and subproject2) using `add_subdirectory`.

In subproject1 and subproject2 CMakeLists.txt:

- It sets the project name to "subproject1" and "subproject2" respectively.

- It adds an executable for each subproject with the corresponding source file (main1.cpp and main2.cpp).

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
   ```

## Analyzing the Results
> **_NOTE:_** Ensure that you have cppcheck installed on your system. You can download the latest version from their official website (https://cppcheck.sourceforge.io/) and follow the installation instructions for your operating system.

After building the project, you can run cppcheck on all the source files using the custom target run_cppcheck:
```bash
cmake --build . --target run_cppcheck
```
Cppcheck will analyze the code and display any issues it finds. The output will indicate the potential bugs, errors, or style violations in your code.

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
