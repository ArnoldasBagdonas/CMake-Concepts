# Example Project: Specify C++ Standard
Specifying the C++ standard for a project in CMake is an important step to ensure that your code is compiled and executed using the desired language features and compatibility. 

## Best Practices for Specifying the C++ standard
Here are some best practices for specifying the C++ standard using CMake:


- **Use the CMAKE_CXX_STANDARD variable**: CMake provides a variable called `CMAKE_CXX_STANDARD` that allows you to specify the desired C++ standard for the entire project. This variable sets a default C++ standard that will be used by all targets unless overridden at the target level.
  ```
  set(CMAKE_CXX_STANDARD 11)
  ```
  In this example, the C++ standard is set to C++17 for the entire project. You can replace `17` with the desired C++ standard version, such as `11`, `14`, or `20`.

- **Set the C++ standard at the target level**: If you have multiple targets within your project that require different C++ standards, you can specify the C++ standard individually for each target using the `target_compile_features` command.
  ```
  target_compile_features(my_target PRIVATE cxx_std_20)
  ```
  In this example, the target `my_target` is set to require at least C++20 features. This will override the project-level standard specified by `CMAKE_CXX_STANDARD` for this specific target.

- **Consider compiler support**: It's important to verify that the C++ compiler being used supports the specified C++ standard. CMake will generate an error during configuration if the compiler doesn't support the requested standard. You can use the `target_compile_features` command to enforce the required C++ standard and check for compiler support.
  ```
  target_compile_features(my_target PRIVATE cxx_std_17)
  ```
  By specifying `cxx_std_17`, CMake ensures that the compiler supports at least the C++17 standard for the `my_target` target.

- **Provide fallback options**: To handle situations where the desired C++ standard is not available, it's good practice to provide fallback options. You can use the `CMAKE_CXX_STANDARD_REQUIRED` variable to enforce the specified C++ standard or fallback to a lower version if necessary.
  ```
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_STANDARD 14)
  ```
  In this example, the C++ standard is set to C++14, and `CMAKE_CXX_STANDARD_REQUIRED` is enabled. If the compiler does not support C++14, CMake will generate an error.

- **Use a consistent C++ standard**: It's generally recommended to use a consistent C++ standard across your entire project to maintain code compatibility and readability. Specify the desired C++ standard in the root CMakeLists.txt file using `CMAKE_CXX_STANDARD`, and it will be inherited by all targets and subdirectories.
  ```
  set(CMAKE_CXX_STANDARD 20)
  ```
  By setting this variable in the root CMakeLists.txt file, the specified C++ standard will apply to the entire project unless overridden at the target level.

- **Consider platform-specific differences**: Different compilers and platforms may have varying levels of C++ standard support. Take into account the requirements and limitations of your target platforms to ensure compatibility and adjust the specified C++ standard accordingly.

##  CMakeLists.txt Explanation

The CMakeLists.txt file contains the necessary instructions for CMake to configure and build the project. Here's a breakdown of its contents:

- **CMake Version and C++ Standard**: The file specifies that it requires at least CMake version 3.5 and sets the C++ standard to C++20.

- **Version Extraction**: It defines a regular expression to extract the version string from the source file "cogen.hpp" using the pattern #define COGEN_VERSION followed by a version number. The extracted version string is then used for project versioning.

- **Project Definition**: The project is defined with the name "exampleproject", indicating that it is a C++ project with the specified version string.

- **Version Checking**: It checks the minor version of the project. If the minor version is less than 2, it displays an error message and terminates the configuration. Otherwise, it displays the version string as a status message.

- **Include Directories**: The "include" directory is included, allowing the compiler to find the necessary header files during compilation.

- **Executable Target**: An executable target is created with the name "exampleproject" and the source file "main.cpp".

- **Include Directories for the Target**: The "include" directory is added to the include directories of the target, ensuring that the necessary header files are accessible during the build process.

## main.cpp, cogen.hpp: Coroutines in C++

Coroutines are a powerful language feature introduced in C++20 that allow for cooperative multitasking, state machines, and asynchronous programming. Coroutines enable functions to be suspended and resumed, allowing for sequential programming with concurrency.

With coroutines, you can write asynchronous code in a more readable and intuitive manner compared to traditional callback-based or thread-based approaches. Coroutines facilitate writing code that looks sequential and improves its maintainability.

Coroutines are also beneficial in implementing state machines. They allow you to model complex state-based behavior by suspending and resuming the execution of a coroutine. This makes it easier to handle asynchronous operations within a state machine and simplifies the code's structure.

Additionally, coroutines excel in scenarios where cooperative multitasking is required. Tasks can voluntarily yield control, allowing other tasks to execute. This cooperative approach to multitasking can be useful in event-driven systems or environments with limited resources.

To dive deeper into coroutines and explore their full potential, refer to the following resources:
- [cppreference.com](https://en.cppreference.com/w/cpp/language/coroutines): Provides comprehensive documentation on coroutines in C++ and covers various aspects, including syntax, usage patterns, and examples.

## Building the Example

To perform an out-of-source build, follow these steps:

1. Create a new directory for the build process. This directory can be named `build`, `bin`, or any other descriptive name.
2. Navigate to the newly created build directory:
   ```bash
   mkdir build && cd build
   ```
3. Run the CMake command from the build directory, specifying the path to the source code directory. For example:
   ```bash
   cmake /path/to/source/code
   ```
4. CMake will generate the build files (e.g., Makefiles, Visual Studio solution files) in the build directory based on the CMakeLists.txt file in the source code directory.
5. Build the project using the generated build system (e.g., Makefiles):
   ```bash
   cmake --build .
   ```
6. The built binaries and artifacts will be placed in the build directory, keeping them separate from the source code.
7. From the build directory, run the resulting executable:
   ```bash
   ./hello
   ```
You should see the output from the "hello" program.

> **_NOTE:_** It's important to note that the build directory should be excluded from version control systems (e.g., Git) by adding it to the project's .gitignore file. This ensures that the build artifacts are not inadvertently committed to the repository.

## Contributing

Contributions to this repository are welcome! If you have additional examples, improvements, or bug fixes, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on contributing.

## License

This repository is licensed under the MIT License. See the LICENSE.md file for more information.
