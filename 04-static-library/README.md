# Example Project: Static Library Best Practices

This example project demonstrates the best practices for creating a static library in Linux.

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

## Best Practices for Creating a Static Library

- **Organize Your Project Directory**: Create a well-structured project directory with separate folders for source code, header files, libraries, and build artifacts.

- **Create a CMakeLists.txt File**: Use CMake to manage the build process of your project. Create a `CMakeLists.txt` file that includes instructions for building the static library.

- **Set Minimum Required CMake Version**: Specify the minimum version of CMake required for your project to ensure compatibility.

- **Set Project Name and Languages**: Set the project name and the programming languages used in your project.

- **Create Library Target**: Use the `add_library` command in CMake to define the static library target. Specify the source files to be compiled into the library.

- **Include Directories**: If your library depends on header files located in specific directories, use the `target_include_directories` command to specify those directories.

- **Set Compiler Options and Features**: Use the `target_compile_options` and `target_compile_features` commands to set compiler options and features required by your library.

- **Link Dependencies**: If your library depends on other libraries, use the `target_link_libraries` command to link them.

- **Build and Install**: Add instructions to build and install your library, specifying the installation directory for the static library on the system.

- **Document Usage**: Provide clear documentation on how to include and use the static library in other projects or applications.

Remember, these best practices serve as guidelines, and you can adapt them based on your specific project requirements and constraints.

##  CMakeLists.txt Explanation

The CMakeLists.txt file contains the necessary instructions for CMake to configure and build the project. Here's a breakdown of its contents:

- **Setting the Minimum Required CMake Version**: Specifies the minimum version of CMake required to build the project. This ensures that developers using older versions of CMake are notified that they need to update to a newer version.

- **Setting the Project Name**: Defines the name of the project being built. It provides a unique identifier for the project and is used in subsequent commands to refer to the project.

- **Creating a Static Library Target**: Creates a static library target named "vegetable_library". This target will compile the source file "src/vegetable.cpp" into a static library that can be used by other parts of the project.

- **Specifying Include Directories for the Library**: Sets the include directories for the "vegetable_library" target. This allows users of the library to include the header files from the "include" directory without specifying the full path.

- **Creating an Executable Target**: Creates an executable target named "exampleproject_binary". This target represents the final executable that will be built from the source file "src/main.cpp" and any additional source files.

- **Linking the Library to the Executable**: Links the "vegetable_library" target to the "exampleproject_binary" target. This ensures that the executable is linked with the static library, enabling it to use the functions and symbols defined in the library.

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
