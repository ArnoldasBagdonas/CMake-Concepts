# CMake Concepts Examples

## Table of Contents

- [Introduction](#introduction)
- [CMake Project Concepts](#cmake-project-concepts)
- [Examples](#examples)
- [Getting Started](#getting-started)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This repository provides examples and demonstrations of best practices in CMake, a popular build system tool widely appreciated among software engineers. The examples highlight various concepts and techniques that are commonly favored in projects using the CMake family of tools.

These detailed topics offer valuable insights into project lifecycle management with the CMake family of tools, helping you effectively develop and manage your projects from start to finish:

![](CMakeFlowchart.jpg)

- C, CMake time
- G, Generation time
- B, Build time
- T, CTest time
- D, CDash time
- I, Install time
- PI, Package install time

## CMake Project Concepts

This section delves into more details about best practices in the following areas:

1. **Hello World**: Demonstrates the concept of out-of-source builds, keeping the source directory clean.
2. **Configure Header File**: Explains how to use a configuration header file to set project-specific variables. **Feature**: Some times it is important to use a static template file (not header file!), this allow to avoid unnecessary recompilation of files that don't require any changes, thus speeding up the build process.
3. **Specify C++ Standard**: Shows how to specify the C++ standard for the project.  **Feature**: This example project defines a regular expression to extract the version string from the source file "cogen.hpp" using the pattern #define COGEN_VERSION followed by a version number. The extracted version string is then used for project versioning.**Feature**: It also shows how to use coroutines, a powerful language feature introduced in C++20 that allow for cooperative multitasking, state machines, and asynchronous programming.
4. **Static Library**: Illustrates the creation and usage of a static library.
5. **Shared Library**: Covers the creation and usage of a shared library.
6. **Third-Party Library**: Provides insights into integrating and managing third-party libraries.
7. **Code Generation**: Demonstrates code generation techniques and their use cases. **Feature**: This example project has python generator utility controlled by command line arguments that could be inegrated into cmake prject using two different approaches.
8. **Testing Support**: Covers testing practices and shows how to use and configure external testing frameworks like Google Test (gtest) and Catch2.
9. **Installing**: Explains the installation process for the project.
10. **Development using Devcontainer**: Guidelines on using DevContainer for development.
11. **Static Code Analysis**: Discusses static code analysis tools like Clang's scan-build and cppcheck.
12. **CDash and CI Pipeline**: Covers the usage of CDash and continuous integration (CI) pipelines, including code coverage and sanitizers.
13. **Code Style Guidelines**: Describes the usage of Clang-format for enforcing code style guidelines.
14. **Documentation Generation**: Demonstrates generating project documentation using tools like Doxygen or Sphinx.


Each concept is demonstrated in a dedicated example folder containing relevant source code, Dockerfiles, and instructions on how to run and test the example. Refer to the individual example folders for detailed information on each concept implementation.

## Getting Started

To get started with the examples, follow these steps:

1. Clone this repository: `git clone git@github.com:ArnoldasBagdonas/CMake-Concepts.git`
2. Navigate to the desired example folder.
3. Follow the instructions provided in the example's README to build and run the example.

## Development using Devcontainer

The examples in this repository are designed to be used with Visual Studio Code's Remote - Containers extension. This extension allows you to develop inside a containerized environment that includes all the necessary dependencies for building and running the examples.

To use Devcontainer:

1. Install Visual Studio Code: [https://code.visualstudio.com/](https://code.visualstudio.com/)
2. Install the Remote - Containers extension: [https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
3. Open the cloned repository in Visual Studio Code.
4. Click on the green "Open a Remote Window" button in the bottom-left corner of the Visual Studio Code window.
5. Select "Open Folder in Container" and choose the repository folder.
6. Visual Studio Code will automatically build the Devcontainer environment and open a new window with the containerized development environment.
7. From the Devcontainer terminal, navigate to the desired example folder and follow the instructions provided in the example's README to build and run the example.

Using Devcontainer ensures consistent development environments across different machines and avoids issues related to different system configurations.

## Run PlantUML on the Markdown file

On the command line:

```
plantuml -tpng README.md
```

or run program in a virtual X environment without requiring a physical X server

```
xvfb-run java -jar /plantuml/plantuml.jar -tpng README.md
```

For every PlantUML block in the file, one png diagram is generated. When the markdown to html converter is running, the html will contain image links to the generated images.

Reference: https://gist.github.com/noamtamim/f11982b28602bd7e604c233fbe9d910f

## Contributing

Contributions to this repository are welcome! If you have additional examples or improvements to the existing ones, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on how to contribute.

## License

This repository is licensed under the MIT License. See the LICENSE.md file for more information.
