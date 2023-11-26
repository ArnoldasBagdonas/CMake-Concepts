cmake_minimum_required(VERSION 3.0)
project(ExampleProject VERSION 1.2.3)

set(CMAKE_CXX_STANDARD 11)

# And create a custom command to render PlantUML diagrams in project's *.md files
add_custom_target(PlantUML
    COMMAND ${CMAKE_COMMAND} -P "${CMAKE_SOURCE_DIR}/cmake/RenderPlantUML.cmake"
    COMMENT "Processing Markdown files and rendering PlantUML diagrams"
)

# Find Doxygen package
find_package(Doxygen)

# Add target to generate Doxygen documentation
if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN YES)
    set(DOXYGEN_GENERATE_RTF YES)
    
    set(DOXYGEN_GENERATE_XML YES)
    #set(DOXYGEN_XML_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/doxygen/xml)

    # Configure the Doxyfiles
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen/DoxyfileBreathe.in ${CMAKE_CURRENT_BINARY_DIR}/DoxyfileBreathe @ONLY)

    # Configure the Sphinx conf.py
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/sphinx/conf.py.in ${CMAKE_CURRENT_SOURCE_DIR}/docs/conf.py @ONLY)
    
    # Create a custom target to generate Doxygen configuration
    add_custom_target(doxyconfig ALL COMMAND ${DOXYGEN_EXECUTABLE} -g Doxyfile.in.default
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen
        COMMENT "Generating Doxygen config file" VERBATIM)

    # Create a custom target to generate API documentation with Doxygen
    add_custom_target(doxygen ALL COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM)
    # Add target to build PDF from LaTeX
    find_program(PDFLATEX_EXECUTABLE NAMES pdflatex)

    if(PDFLATEX_EXECUTABLE)
        # Add a custom command to run 'make all-pdf' after the doxygen target's build is complete
        add_custom_command(TARGET doxygen
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/FixLatexCode.cmake
            COMMAND ${CMAKE_MAKE_PROGRAM} -f Makefile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxygen/latex/
            COMMENT "Executing the FixLatexCode.cmake script after Doxygen build and Compiling LaTeX documentation")
    endif()
    
    add_dependencies(doxygen PlantUML)

    # Create a custom target to generate API documentation with Sphinx (html)
    add_custom_target(sphinx_html ALL COMMAND sphinx-build -b html ${CMAKE_CURRENT_SOURCE_DIR}/docs ${CMAKE_CURRENT_BINARY_DIR}/sphinx/html
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs
        COMMENT "Generating API documentation with Sphinx" VERBATIM)

    # Create a custom target to generate API documentation with Sphinx (pdf)
    add_custom_target(sphinx_pdf ALL COMMAND sphinx-build -b latex ${CMAKE_CURRENT_SOURCE_DIR}/docs ${CMAKE_CURRENT_BINARY_DIR}/sphinx/pdf
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs
        COMMENT "Generating API documentation with Sphinx" VERBATIM)
    
    # Add the manual step of executing "make all-pdf" after the sphinx target
    add_custom_command(TARGET sphinx_pdf
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_CURRENT_BINARY_DIR}/sphinx/pdf make all-pdf
        COMMENT "Running 'make all-pdf' after Sphinx build")
        
    add_dependencies(sphinx_html PlantUML)
    add_dependencies(sphinx_pdf PlantUML)

endif()

#add_executable(HelloWorld main.cpp)
