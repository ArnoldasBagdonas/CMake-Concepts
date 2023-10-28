cmake_minimum_required(VERSION 3.0)
project(HelloWorld VERSION 1.2.3)

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

    # Configure the Doxyfile
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

    # Configure the Sphinx conf.py
    # configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs_sphinx/conf.py.in ${CMAKE_CURRENT_SOURCE_DIR}/conf.py @ONLY)
    
    # Create a custom target to generate Doxygen configuration
    add_custom_target(doxyconfig ALL COMMAND ${DOXYGEN_EXECUTABLE} -g Doxyfile.in.default
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating Doxygen config file" VERBATIM)

    # Create a custom target to generate API documentation with Doxygen
    add_custom_target(doxygen ALL COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM)
    
    add_dependencies(doxygen PlantUML)

    # Create a custom target to generate API documentation with Sphinx
    add_custom_target(sphinx ALL COMMAND sphinx-build -b html ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sphinx
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Sphinx" VERBATIM)
    
    add_dependencies(sphinx doxygen)

    # Add target to build PDF from LaTeX
    find_program(PDFLATEX_EXECUTABLE NAMES pdflatex)

    if(PDFLATEX_EXECUTABLE)
        add_custom_target(refman
            COMMAND ${CMAKE_MAKE_PROGRAM} -f Makefile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxygen/latex/
            COMMENT "Compiling LaTeX documentation")
        
        # Add a custom target to fix LaTeX code
        # TODO: figure out how to configure Doxygen properly!
        add_custom_target(latex ALL
            COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/FixLatexCode.cmake
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxygen/latex/
            COMMENT "Fix LaTeX code" VERBATIM)

        # Ensure that code replacement happens before LaTeX compilation
        add_dependencies(latex doxygen)
        add_dependencies(refman latex)
    endif()
endif()

#add_executable(HelloWorld main.cpp)
