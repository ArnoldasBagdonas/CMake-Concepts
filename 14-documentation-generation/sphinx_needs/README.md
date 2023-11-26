# README

## Introduction
This is a simple CMake example project for a book library management program. The project is designed to showcase basic CMake usage and provide a foundation for building a book library management system.

## Clone the Project

To clone this project, follow these instructions:

```bash
git clone <repository_url>
cd <project_directory>
```

## Project Folder Structure

```plaintext
.
├── CMakeLists.txt
├── README.md
├── app
│   ├── CMakeLists.txt
│   └── main.cpp
├── cmake
│   ├── FixLatexCode.cmake
│   └── RenderPlantUML.cmake
├── docs
│   ├── conf.py
│   ├── index.rst
│   ├── _doxygen
│   │   ├── Doxyfile.in
│   │   ├── DoxyfileBreathe.in
│   │   └── custom.css
│   ├── _sphinx
│   │   └── conf.py.in
│   ├── _static
│   ├── implementation
│   │   └── index.rst
│   ├── readme
│   │   └── README.md
│   ├── reports
│   │   └── index.rst
│   ├── requirements
│   │   └── index.rst
│   ├── specifications
│   │   └── index.rst
│   └── testing
│       └── index.rst
├── library_system
│   ├── include
│   │   └── library_system
│   │       └── library_system.hpp
│   └── src
│       └── library_system.cpp
└── test
    ├── CMakeLists.txt
    └── library_system_test.cpp

```

- **Root Directory (.)**:

  - **CMakeLists.txt**: The main CMake configuration file for the entire project.
  
  - **README.md**: The project's main documentation file providing an overview and instructions.

- **app Directory**:

  - **CMakeLists.txt**: CMake configuration for the application component.
  
  - **main.cpp**: The main source file for the application.

- **cmake Directory**:

  - **FixLatexCode.cmake**: A CMake script for fixing LaTeX code.
  
  - **RenderPlantUML.cmake**: A CMake script for rendering PlantUML code.

- **docs Directory**:
  
  - **conf.py**: Configuration file for Sphinx.
  
  - **index.rst**: The main entry point for Sphinx documentation.
  
  - **_doxygen**:

    - **Doxyfile.in**: Input configuration file for Doxygen.
    
    - **DoxyfileBreathe.in**: Input configuration file for Breathe, a Doxygen Python extension.
    
    - **custom.css**: Custom CSS file for Doxygen HTML output.

  - **_sphinx**:
    
    - **conf.py.in**: Input configuration file for Sphinx, a documentation generation tool.
  
  - **_static**: A directory for static files used in documentation.

  - **implementation**:
    - **index.rst**: ReStructuredText file for documenting the implementation.

  - **readme**:
    
    - **README.md**: Documentation specific to the README.

  - **reports**:
    
    - **index.rst**: ReStructuredText file for documenting reports.

  - **requirements**:
    
    - **index.rst**: ReStructuredText file for documenting requirements.

  - **specifications**:
    
    - **index.rst**: ReStructuredText file for documenting specifications.

  - **testing**:
    
    - **index.rst**: ReStructuredText file for documenting testing.

- **library_system Directory**:

  - **include**:
    
    - **library_system**:
      
      - **library_system.hpp**: Header file for the library system.

  - **src**:
    
    - **library_system.cpp**: Source file for the library system.

- **test Directory**:

  - **CMakeLists.txt**: CMake configuration for the tests.
  - **library_system_test.cpp**: Source file for testing the library system.

## CMake Targets

Here are the common CMake targets defined in the CMakeLists.txt for this project:

- **Build**: Compiles the project and generates executable or library files. To build the project, run:
  ```bash
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

### Additional Targets

- **PlantUML**: A custom target to render PlantUML diagrams in the project's '**README.md**' files. This target is automatically invoked during the build process:
  ```bash
  cmake --build . --target PlantUML
  ```

- **Doxygen**: A target to generate documentation using Doxygen:
  ```bash
  cmake --build . --target doxygen
  ```

- **Sphinx HTML**: A target to generate documentation in HTML format using Sphinx:
  ```bash
  cmake --build . --target sphinx_html
  ```

- **Sphinx PDF**: A target to generate documentation in PDF format using Sphinx:
  ```bash
  cmake --build . --target sphinx_pdf
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
