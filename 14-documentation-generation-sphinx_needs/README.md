# CMake Project

This is a generic CMake project that can serve as a starting point for various Doxyegn, Sphinx, Sphinx-Needs documentation generation projects. It includes basic CMake setup, a directory structure, and common CMake targets.

## Standard CMake Targets

1. **Clean**:

    **Description**: Removes all build artifacts and temporary files.
    
    **Usage**:
    ```bash
    cmake --build build/ --target clean
    ```
    
    **Note**: Cleaning is often performed before configuring to ensure a clean build environment.

2. **Configure**:

    **Description**: Configures the project based on the specified build type.
    
    **Usage**:
    ```bash
    cmake -DCMAKE_BUILD_TYPE=Debug -B build/ path/to/source
    ```
    
    **Note**: Use this step to set the desired build type (Debug, Release, etc.) and configure project settings. The -B flag specifies the build directory.


3. **Build**:

    **Description**: Compiles the project and generates executable or library files.
    
    **Usage**:
    ```bash
    cmake --build build/
    ```
    
    **Note**: The build type specified during configuration influences compiler flags and optimizations.

4. **Run**:

    **Description**: Executes the built application.
    
    **Usage**:
    ```bash
    ./build/myapp
    ```
    
    **Note**: Ensure that the project has been successfully built before running the application.

5. **Test**:

    **Description**: Runs tests if you have a testing framework set up.
    
    **Usage**:
    ```bash
    cmake --build build/ --target test
    ```
    
    **Note**: Testing is essential to ensure the correctness of the project. Set up testing configurations in the CMakeLists.txt file.

6. **Package**:

    **Description**: Creates a distribution package of the project.
    
    **Usage**:
    ```bash
    cmake --build build/ --target package
    ```
    
    **Note**: Packaging bundles the project into a distributable format for sharing or deployment.

7. **Install**:

    **Description**: Installs the project (e.g., copies files to system directories).
    
    **Usage**:
    ```bash
    cmake --build build/ --target install
    ```
    
    **Note**: Installation is useful for deploying the project on the system.

## Project-Specific Targets

1. **Render PlantUML Diagrams**:

    **Description**: Renders PlantUML diagrams in the project's README.md files.
    
    **Usage**:
    ```bash
    cmake --build . --target render_plantuml
    ```

2. **Generate Doxygen Documentation**:

    **Description**: Generates documentation using Doxygen.
    
    **Usage**:
    ```bash
    cmake --build . --target generate_doxygen
    ```

3. **Generate Sphinx HTML Documentation**:

    **Description**: Generates documentation in HTML format using Sphinx.
    
    **Usage**:
    ```bash
    cmake --build . --target generate_sphinx_html
    ```

4. **Generate Sphinx PDF Documentation**:

    **Description**: Generates documentation in PDF format using Sphinx.
    
    **Usage**:
    ```bash
    cmake --build . --target generate_sphinx_pdf
    ```

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
