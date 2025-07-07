# Example Project: Dynamic Library Best Practices

This example project demonstrates the best practices for creating a dynamic library in Linux.

## Difference Between Shared and Static Libraries in Linux

### Shared Libraries

Shared libraries, also known as dynamic libraries, have the file extension `.so` (shared object) in Linux. Key characteristics of shared libraries include:

- Loaded into memory at runtime when the program starts or explicitly requested
- Multiple programs can use the same shared library, reducing memory footprint
- Updates or patches to shared libraries benefit all programs using them without recompilation
- Smaller in size compared to static libraries
- Allow for dynamic linking at runtime
- Can be loaded and unloaded during program execution

### Static Libraries

Static libraries, on the other hand, have the file extension `.a` (archive) in Linux. Key characteristics of static libraries include:

- Linked directly into the program at compile-time, resulting in a standalone executable
- Each program that uses a static library has its own copy of the library code, increasing executable size
- Programs using static libraries need to be recompiled and relinked to benefit from library updates or patches
- Larger in size compared to shared libraries
- Allow for static linking at compile-time
- Cannot be loaded or unloaded during program execution

## Best Practices for Creating a Shared Library

- **Directory Structure**: Maintain a well-organized directory structure for your project. Typically, you will have a separate directory for source files (`src`), header files (`include`), and CMake-related files (CMakeLists.txt).

- **CMakeLists.txt**: Create a `CMakeLists.txt` file in the root directory of your project. This file will define the project, set compilation options, and specify the targets.

- **Add_library**: Use the `add_library` command in your `CMakeLists.txt` to define the shared library target. Provide a name for your library and specify the source files required to build it. For example:
   ```
   add_library(mylib SHARED source1.cpp source2.cpp)
   ```
- **Include Directories**: Use the `target_include_directories` command to specify the directories containing the header files required by your shared library. This ensures that other components using the library can find the necessary headers. For example:
   ```
   target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
   ```
- **Compiler Flags**: If your library requires specific compiler flags or options, you can use the `target_compile_options` command to set them. This ensures consistent compilation across different components using your library.

- **Export Library**: To enable other projects to use your shared library, you can export it using the `install` command in your `CMakeLists.txt`. This copies the built library and associated headers to a specified location. For example:
   ```
   install(TARGETS mylib LIBRARY DESTINATION lib)
   install(DIRECTORY include/ DESTINATION include)
   ```
- **Linking**: When using your shared library in another project, you need to link against it. Use the `target_link_libraries` command in the CMakeLists.txt of the consumer project to specify the required libraries. For example:
   ```
   target_link_libraries(myapp mylib)
   ```
- **Versioning**: Consider using versioning for your shared library to handle compatibility between different versions. CMake provides facilities to set and manage version numbers for your library.

- **Testing**: Include tests for your shared library to ensure its functionality and catch any potential issues. Use CMake's testing facilities (e.g., `add_test`) to define and run tests.

- **Documentation**: Provide clear and concise documentation for your shared library. Include instructions on how to build, install, and use it, along with examples and API references.

Remember to regularly test and update your CMake files as your project evolves. By following these best practices, you can create and use shared libraries effectively in your CMake-based projects.

##  CMakeLists.txt Explanation

The CMakeLists.txt file contains the necessary instructions for CMake to configure and build the project. Here's a breakdown of its contents:

- **CMake minimum required version**: Specifies that the CMake version 3.5 or higher is needed to run this build script.

- **Project declaration**: Sets the name of the project as "exampleproject".

- **Library creation**: Creates a shared library target named "fruit_library" and specifies the source file "fruit.cpp". This library will be built from the source file and can be used by other targets.

- **Library alias**: Creates an alias for the "fruit_library" target with the name "plants::fruit". This alias allows for a more organized and readable namespace when using the library.

- **Include directories**: Specifies the include directories for the "fruit_library" target. The "PUBLIC" keyword indicates that these include directories will be visible to other targets that link against the library.

- **Executable creation**: Creates an executable target named "exampleproject_binary" and specifies the source file "main.cpp". This executable will be built from the source file.

- **Linking**: Links the "exampleproject_binary" target with the "fruit_library" target. The "PRIVATE" keyword indicates that the linking is specific to this target only.

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
   ./exampleproject_binary
   ```
You should see the output from the "hello" program.

> **_NOTE:_** It's important to note that the build directory should be excluded from version control systems (e.g., Git) by adding it to the project's .gitignore file. This ensures that the build artifacts are not inadvertently committed to the repository.

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
