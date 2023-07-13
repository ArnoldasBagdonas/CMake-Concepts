# Example Project: Installing a project using CMake

By following these best practices, you can create a robust and user-friendly installation process for your project using CMake.

## Best Practices for Installing a project using CMake

- **Organize your project structure**: It's important to have a well-organized project structure. Create separate directories for source code, headers, libraries, and any other relevant files. This makes it easier to manage and maintain your project.

- **Use an out-of-source build**: It is recommended to perform an out-of-source build, which means you build your project in a separate directory from the source code. This keeps your source code directory clean and avoids cluttering it with build artifacts.

- **Add installation instructions in CMakeLists.txt**: In your project's CMakeLists.txt file, add instructions to install the necessary files, such as executables, libraries, headers, and other resources. Use the install command provided by CMake to specify the files and their destination paths.

- **Define installation destinations**: Specify the installation destinations for different types of files using CMake variables such as CMAKE_INSTALL_PREFIX, CMAKE_INSTALL_BINDIR, CMAKE_INSTALL_LIBDIR, and so on. These variables determine where your files will be installed on the target system.

- **Provide platform-independent installation paths**: When defining installation paths, try to make them platform-independent. Use CMake's generator expressions, such as $<INSTALL_PREFIX> or $<INSTALL_BINDIR>, to dynamically determine the installation paths based on the target platform.

- **Use COMPONENT to group files**: CMake's install command allows you to specify the COMPONENT parameter to group files into logical components. For example, you can group header files under the "dev" component and libraries under the "runtime" component. This makes it easier for users to selectively install specific components.

- **Consider versioning and compatibility**: If your project provides libraries or APIs, consider using versioning schemes to ensure compatibility and manage updates. CMake provides tools like SOVERSION and VERSION to specify library version information during installation.

- **Provide uninstallation support**: Along with installation, consider adding support for uninstallation. You can use CMake's install command with the DESTINATION option to specify where to install an "uninstall" script. This script can remove the installed files when executed.

- **Use CPack for packaging**: If you want to distribute your project as a package (e.g., a tarball or an installer), consider using CPack, a CMake component for packaging. CPack provides various generators to create packages for different platforms.

- **Test the installation process**: Finally, thoroughly test the installation process on different platforms to ensure that your project can be successfully installed and executed on various systems. This helps identify and fix any installation-related issues before releasing your project.


##  CMakeLists.txt Explanation

The CMakeLists.txt file contains the necessary instructions for CMake to configure and build the project. Here's a breakdown of its contents:

- **Setting the minimum required version of CMake**: Specifies the minimum version of CMake required to build the project. In this case, it is set to version 3.5.
- **Setting the project name**: Names the project. This is used internally by CMake to identify the project.
- **Enabling building with the install RPATH**:
    - **CMAKE_SKIP_BUILD_RPATH**: Set to FALSE to include the RPATH during the build process.
    - **CMAKE_BUILD_WITH_INSTALL_RPATH**: Set to FALSE to exclude the install RPATH during the build process.
    - **CMAKE_INSTALL_RPATH**: Sets the runtime search path (RPATH) for the installed binaries. It determines where the installed binaries will search for libraries.
    - **CMAKE_INSTALL_RPATH_USE_LINK_PATH**: Set to TRUE to make the installed binaries use the linker's search path for the RPATH.
- **Adding a shared library target**: Defines a shared library target called "fruit_library" and specifies the source file "fruit.cpp".
- **Adding include directory to library's include paths**: Includes the "include" directory in the library's include paths, allowing access to its header files.
- **Adding an executable target**: Defines an executable target called "exampleproject_inst_bin" and specifies the source file "main.cpp".
- **Linking the shared library with the executable**: Links the "fruit_library" with the executable target "exampleproject_inst_bin".
- **Installing the binary to the "bin" directory**: During installation, the "exampleproject_inst_bin" binary will be copied to the "bin" directory.
- **Installing the shared library to the "lib" directory**: During installation, the "fruit_library" shared library will be copied to the "lib" directory.
- **Installing the contents of the "include" directory**: During installation, the contents of the "include" directory will be copied to the "include" directory.
- **Installing the configuration file**: During installation, the "exampleproject_inst_bin.conf" file will be copied to the "etc" directory.
- **Adding the uninstall target**: Checks if the uninstall target exists and adds it if it doesn't. The uninstall target allows for removing the installed files and directories when invoked.

These instructions set up the project, define build targets, specify dependencies, configure the installation process for the project's binary, library, header files, and configuration file, and add an uninstall target for removing the installed files and directories.

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
   ./hello
   ```
You should see the output from the "hello" program.

> **_NOTE:_** It's important to note that the build directory should be excluded from version control systems (e.g., Git) by adding it to the project's .gitignore file. This ensures that the build artifacts are not inadvertently committed to the repository.

## Installing the Example
To install the example project on your system, follow these steps:

1.  Build the project using the instructions mentioned in the "Building & Running the Example" section.
2. Once the project is successfully built, navigate to the build directory.
3. Open a terminal or command prompt in that directory.
4. Run the following command to install the project:
   ```bash
   cmake --build . --target install
   ```
   This command will install the built executable, shared library, header files, and other necessary files to their respective system directories.

   If you encounter a permission error during installation, consider the following options to resolve it:

      - **Install to a user-specific location**: Modify the CMakeLists.txt file and change the installation destination to a directory within your user's home directory. For example:
      ```
      install(TARGETS exampleproject_inst_bin
         DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
      )
      ```

      - **Use sudo to gain root access**: If you have sudo access on your devcontainer, run the CMake installation command with sudo to perform the installation as the root user. For example:
      ```bash
      sudo cmake --build . --target install
      ```

      - **Modify the devcontainer's configuration**: Adjust the configuration of your devcontainer to allow installation by the non-root user. This may involve modifying Dockerfile or devcontainer.json files to grant appropriate permissions for the installation.

> **_NOTE:_** The installation will be performed using the Release build type, as specified during the CMake configuration step.

## Uninstalling the Example
If you want to remove the installed example project from your system, follow these steps:

1. Open a terminal or command prompt in the build directory where the project was installed.
2. Run the following command to uninstall the project:
   ```bash
   cmake --build . --target uninstall
   ```


## Contributing

Contributions to this repository are welcome! If you have additional examples, improvements, or bug fixes, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on contributing.

## License

This repository is licensed under the MIT License. See the LICENSE.md file for more information.
