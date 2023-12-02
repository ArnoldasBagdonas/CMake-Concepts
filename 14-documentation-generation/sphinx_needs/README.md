# README

## Introduction
This is a simple CMake example project for a book library management program. The project is designed to showcase basic CMake usage and provide a foundation for building a book library management system.

## Installation and Setup

### Visual Studio Code

1. **Download and Install Visual Studio Code**:

    - Download Visual Studio Code from the official website: [Visual Studio Code](https://code.visualstudio.com/).
    - Follow the installation instructions for your operating system.

2. **Install Required Extensions**:

    - Open Visual Studio Code.
    - Go to the Extensions view by clicking on the Extensions icon in the Activity Bar on the side of the window or use the shortcut '**Ctrl+Shift+X**'.
    - Install the following extensions:
      - Dev Containers (containers)

### Docker

1. **Download and Install Docker**:

    - Download Docker from the official website: [Docker](https://www.docker.com/).
    - Follow the installation instructions for your operating system or install the latest Docker release by executing:
      ```bash
      curl -sSL https://get.docker.com/ | sudo sh
      ```

2. Verify Docker Installation:

    - Open a terminal and run the following command to verify the Docker installation:
      ```bash
      docker --version
      ```

3. **Start Docker Desktop**:

    - Launch Docker Desktop from your applications menu or start menu.

### Clone the Project

To clone this project, follow these instructions:

```bash
git clone <repository_url>
cd <project_directory>
```

### Setting Up DevContainer

1. **Open Project in Visual Studio Code**:

    - Launch Visual Studio Code.
    - Open the project in Visual Studio Code.

2. **Rebuild and Use DevContainer for Containerized Development**:

    - In VS Code, run the '**Dev Containers: Rebuild and Reopen in Container**' command from the Command Palette or use the shortcut '**F1**'

3. **Subsequent Access to DevContainer**:

    - After the initial setup, for subsequent access, you only need to:
    - Look for the green icon in the bottom-right corner labeled '**Open a Remote Window**'.
    - Click on the icon.
    - Select '**Reopen in Container**'.

## Project Folder Structure

```plaintext
# LC_ALL=C tree
.
|-- CMakeLists.txt
|-- README.md
|-- app
|   |-- CMakeLists.txt
|   `-- main.cpp
|-- cmake
|   |-- FixLatexCode.cmake
|   `-- RenderPlantUML.cmake
|-- docs
|   |-- _doxygen
|   |   |-- Doxyfile.in
|   |   |-- DoxyfileBreathe.in
|   |   `-- custom.css
|   |-- _sphinx
|   |   `-- conf.py.in
|   |-- _static
|   |-- conf.py
|   |-- implementation.rst
|   |-- index.rst
|   |-- readme
|   |   `-- README.md
|   |-- reports.rst
|   |-- requirements.rst
|   |-- specifications.rst
|   `-- testing.rst
|-- library_system
|   |-- include
|   |   `-- library_system
|   |       `-- library_system.hpp
|   `-- src
|       `-- library_system.cpp
`-- test
    |-- CMakeLists.txt
    `-- library_system_test.cpp
```

- **Root Directory (.)**:

  - **CMakeLists.txt**: The main CMake configuration file for the entire project.
  
  - **README.md**: The project's main documentation file provides an overview and instructions. Before the documentation target build, a copy of this file is created in the docs/readme folder.

- **app Directory**:

  - **CMakeLists.txt**: CMake configuration for the application component.
  
  - **main.cpp**: The main source file for the application.

- **cmake Directory**:

  - **FixLatexCode.cmake**: A CMake script for fixing LaTeX code.
  
  - **RenderPlantUML.cmake**: A CMake script for rendering PlantUML code in all Markdown files found in project subfolders.

- **docs Directory**:

  - **_doxygen Directory**:

    - **Doxyfile.in**: Input configuration file for the Doxygen documentation, used by the CMake configure step.
    
    - **DoxyfileBreathe.in**: Input configuration file for Breathe, a Doxygen Python extension, used by the CMake configure step.
    
    - **custom.css**: Custom CSS file for Doxygen HTML output.

  - **_sphinx Directory**:
    
    - **conf.py.in**: Input configuration file for Sphinx, a documentation generation tool, used by the CMake configure step.
  
  - **_static Directory**: A directory for static files used in documentation.

  - **conf.py**: Configuration file for Sphinx. Created by the CMake configure step from '**conf.py.in**'.

  - **index.rst**: The main entry point for Sphinx documentation.

  - **readme Directory**: This folder is needed to store all images created by the PlantUML CMake target.
    
    - **README.md**: A copy of the project's README.md file made from the file in the root folder.

  - **requirements.rst**: ReStructuredText file for documenting requirements.

  - **specifications.rst**: ReStructuredText file for documenting specifications.

  - **implementation.rst**: ReStructuredText file for documenting the implementation.

  - **testing.rst**: ReStructuredText file for documenting testing.

  - **reports.rst**: ReStructuredText file for documenting reports.

- **library_system Directory**:

  - **include Directory**:
    
    - **library_system Directory**:
      
      - **library_system.hpp**: Header file for the library system.

  - **src Directory**:
    
    - **library_system.cpp**: Source file for the library system.

- **test Directory**:

  - **CMakeLists.txt**: CMake configuration for the tests.
  - **library_system_test.cpp**: Source file for testing the library system.

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

## Contributing

Contributions to this repository are welcome! If you have additional examples or improvements to the existing ones, feel free to submit a pull request. Please refer to the CONTRIBUTING.md file for guidelines on how to contribute.

## License

This project is licensed under the [MIT License](https://opensource.org/license/mit/). The MIT License is a permissive open-source license that allows you to:

- **Use**: Copy and modify the source code.

- **Distribute**: Redistribute and sublicense the code.

- **Commercial Use**: Use the code in commercial projects.

**Disclaimer**:

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
