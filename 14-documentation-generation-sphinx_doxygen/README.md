# CMake Project

This is a generic CMake project that can serve as a starting point for various Doxyegn, Sphinx documentation generation projects . It includes basic CMake setup, a directory structure, and common CMake targets.

## CMake Targets
Here are the common CMake targets you can use in this project:

- **Build**: Compiles the project and generates executable or library files. To build the project, run:
  ```bash
  mkdir build
  cmake -S . -B build
  cmake --build build/
  ```
- **Clean**: Removes all build artifacts. To clean the project, run:
  ```bash
  cmake --build build/ --target clean
  ```
- **Run**: Executes the built application. To run the project, run:
  ```bash
  ./build/myapp
  ```
- **Test**: Runs tests if you have a testing framework set up. To run tests, use:
  ```bash
  cmake --build build/ --target test
  ```
- **Install**: Installs the project (e.g., copies files to system directories). To install the project, use:
  ```bash
  cmake --build build/ --target install
  ```
- **Package**: Creates a distribution package of the project. To create a package, run:
  ```bash
  cmake --build build/ --target package
  ```

Feel free to modify this project structure and add more targets according to your specific project requirements. Make sure to update the CMakeLists.txt file to reflect any changes in your project's configuration.

## Getting Started

To get started with the examples, follow these steps:

1. Clone this repository: `git clone git@github.com:ArnoldasBagdonas/CMake-Concepts.git`
2. Navigate to the desired example folder: `cd cmake-concepts-examples/<example-folder>`
3. Follow the instructions provided in the example's README to build and run the example.

Make sure you have Docker installed and properly configured on your system.

## Contributing

Contributions to this repository are welcome! If you have additional examples or improvements to the existing ones, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on how to contribute.

## License

This repository is licensed under the MIT License. See the LICENSE.md file for more information.