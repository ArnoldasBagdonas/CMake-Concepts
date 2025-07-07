# Example Project: Third-Party Library Best Practices

This example project demonstrates the best practices for using a third-party library in Linux.

## Best Practices for Integrating and Managing Third-Party Libraries

- **Use Find Modules**: CMake provides a mechanism called "Find Modules" to locate third-party libraries on the system. Whenever possible, use these modules instead of hardcoding library paths. You can find existing Find Modules in the CMake distribution or create your own if necessary.

- **Prefer Package Configurations**: Many modern libraries provide package configurations, which are CMake files that expose the necessary variables and targets for easy integration. Whenever available, prefer using package configurations over manual configuration.

- **Separate Library Configuration**: It's generally a good practice to create a separate CMake file or directory for each third-party library you want to integrate. This isolates the library-specific configuration, making it easier to maintain and update.

- **Use External Project**: If a library doesn't provide a CMake package configuration or if you need more control over the build process, you can use CMake's ExternalProject module. This module allows you to download, build, and install a library as part of your CMake build process.

- **Set CMake Variables**: When integrating a third-party library, you often need to set specific CMake variables to control its behavior. Instead of modifying the library's original CMake files, set these variables in your own CMake files using the set() command.

- **Specify Dependencies**: If your project depends on multiple third-party libraries, make sure to specify the correct dependencies using the target_link_libraries() command. This ensures that the libraries are linked in the correct order and that their dependencies are resolved.

- **Handle Library Not Found**: If a required library is not found on the system, handle the situation gracefully by providing a meaningful error message and instructions for the user on how to install the library. You can use the message() command to display informative messages during the configuration process.

- **Version Compatibility**: Consider specifying version constraints for third-party libraries if your project requires a specific version or range of versions. This helps ensure compatibility and avoids unexpected issues with different library versions.

- **CMake Options**: For more flexibility, consider providing CMake options to control the integration of third-party libraries. These options can enable/disable specific features or choose between different library versions or implementations.

- **Document Integration Steps**: Lastly, document the integration steps for each third-party library in your project's documentation or README file. Include any specific configuration settings, dependencies, and instructions for installing the library.

##  CMakeLists.txt Explanation

The CMakeLists.txt file contains the necessary instructions for CMake to configure and build the project. Here's a breakdown of its contents:

- **Set the minimum required version of CMake**: This line specifies the minimum version of CMake required to build the project. In this case, it's set to version 3.5.

- **Set the project name**: The project command sets the name of the project. In this case, it's set to "exampleproject".

- **Find the Boost library**: The `find_package` function will search for CMake modules in the formant "FindXXX.cmake" from the list of folders in CMAKE_MODULE_PATH. The exact format of the arguments to find_package will depend on the module you are looking for. This is typically documented at the top of the FindXXX.cmake file. `find_package(Boost ...)` in this example searches for the Boost library on the system with a minimum version of 1.46.1. The `REQUIRED` keyword indicates that the Boost library is essential for the project, and if it is not found, a fatal error will be raised.

   The command also specifies the required components of the Boost library using the `COMPONENTS` keyword. In this case, we are specifying two components: 'filesystem' and 'system'. These components represent different functionality provided by the Boost library. The 'filesystem' component is used for file system operations, while the 'system' component provides various system-related utilities.

   When the find_package command is executed successfully, it sets several variables related to the Boost library. These variables can be used later in the CMake script or in other CMake commands. Here are the commonly exported variables when using `find_package(Boost ...)`:

   - **Boost_FOUND**: This variable is set to `TRUE` if the Boost library is found on the system, and `FALSE` otherwise. It can be used in conditional statements to check if Boost was successfully located.
   - **Boost_INCLUDE_DIRS**: This variable contains a list of directories where the Boost header files are located. These directories can be used to include the Boost headers in the source code.
   - **Boost_LIBRARIES**: This variable contains the full paths to the Boost library files. It provides the necessary information to link against the Boost library during the build process.
   - **Boost_VERSION**: This variable contains the version number of the Boost library that was found. It can be used to ensure that the correct version of Boost is being used in the project.

   These exported variables allow you to access the information about the Boost library that was found during the CMake configuration process. You can use them to include the Boost headers (`Boost_INCLUDE_DIRS`) and link against the Boost libraries (`Boost_LIBRARIES`) in your project. The Boost_FOUND variable can be used to conditionally handle situations when Boost is not found, such as displaying an error message or taking alternative actions. The `Boost_VERSION` variable provides the version number for version-specific handling if needed.

- **Check if Boost was found**: The `if(Boost_FOUND)` condition checks if Boost was found on the system. If it was found, it displays the message "Boost found". Otherwise, it displays a fatal error message and stops the configuration process.

- **Create an executable**: The add_executable command creates an executable named 'exampleproject_binary' from the source file 'main.cpp'. This executable will be built as part of the project.

- **Link the Boost library**: The target_link_libraries command links the 'exampleproject_binary' executable with the 'filesystem' component of the Boost library. This ensures that the necessary Boost libraries are linked during the build process.

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
