# Example Project: Out-of-Source Builds

Encouraging out-of-source builds is recommended as it keeps the source code directory clean and avoids cluttering it with build artifacts. This practice involves creating a separate directory for the build process, which helps maintain a clear separation between the source and build directories.

## Out-of-Source Builds

Out-of-source builds are a recommended practice when using CMake. This approach involves separating the build artifacts from the source code by creating a dedicated build directory. By doing so, the source code directory remains clean and uncluttered, while the build directory contains all the generated files.

Benefits of out-of-source builds include:

- **Clean Source Code Directory**: Keeping the source code directory free from build artifacts makes it easier to navigate, understand, and manage the codebase.
- **Isolation of Build Artifacts**: Separating build artifacts from the source code reduces the risk of accidental modification or deletion of important files during the build process.
- **Easy Cleanup**: Cleaning the build artifacts is as simple as removing the build directory, ensuring a clean build environment whenever needed.
- **Support for Multiple Configurations**: Out-of-source builds allow you to easily switch between different build configurations by creating separate build directories for each configuration.
- **Enables Parallel Builds**: Out-of-source builds enable concurrent or parallel builds, utilizing system resources effectively without interfering with the source code.

To perform an out-of-source build, simply create a new directory (e.g., `build`) and run CMake from within that directory. Refer to the examples in this repository for more details on how to set up and use out-of-source builds effectively.

## CMake Basics and Best Practices

Understanding the basics of CMake is crucial for effectively configuring and building projects. Here are some best practices to follow:

- **Specify the Minimum Required CMake Version**: Use the `cmake_minimum_required()` command at the beginning of your CMakeLists.txt file to ensure compatibility with the required CMake version. This practice ensures that developers attempting to build your project have a compatible CMake version installed.

- **Set the Project Name**: Use the `project()` command to set a descriptive name for your project. This command provides essential information about your project to CMake and is used for generating build system files.

- **Add Executables and Libraries**: Use the `add_executable()` and `add_library()` commands to define the targets (executables or libraries) to be built. Specify the relevant source files, dependencies, and compile options using these commands.

- **Use Target Properties**: Leverage CMake's target properties to fine-tune build settings for each target. Set compiler flags, include directories, and other options specific to each target using the `target_compile_options()`, `target_include_directories()`, and related commands.

- **Manage External Dependencies**: Utilize CMake's built-in support for managing external dependencies. Use the `find_package()` command to locate and configure third-party libraries and use `target_link_libraries()` to link them with your targets.

- **Encourage Modularity**: Break down your project into modular components and create separate CMakeLists.txt files for each component. This practice promotes maintainability, scalability, and ease of understanding.

- **Documentation Generation**: Consider using CMake to automatically generate project documentation. CMake can be configured to work with tools like Doxygen or Sphinx, enabling easy and up-to-date documentation generation.

By following these best practices and leveraging the examples provided in this repository, you can harness the power of CMake to efficiently build, manage, and maintain your projects.

## Hello world example

The `CMakeLists.txt` file in this example contains the following commands:
```bash
cmake_minimum_required(VERSION 3.5)
project(hello)
add_executable(hello main.cpp)
```
Let's break down each command and its purpose:

- **cmake_minimum_required(VERSION 3.5)**: This command sets the minimum required version of CMake that can be used to build the project. In this case, the minimum required version is set to 3.5. This ensures that developers attempting to build the project have a compatible CMake version installed.

- **project(hello)**: The project() command is used to set the project name. In this case, the project is named "hello". The project name is important for generating build system files and ensuring that CMake operates correctly with your project.

- **add_executable(hello main.cpp)**: The add_executable() command is used to add an executable target to the project. It specifies the name of the executable, which is "hello" in this case, and the source file(s) associated with it. In this example, the main.cpp file is the source file containing the entry point of the application.


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
