# Set the minimum required version of CMake
cmake_minimum_required (VERSION 3.5)

# Set the project name
project(exampleproject)

# Find the cppcheck executable
find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)

# Check if cppcheck is found
if(CPPCHECK_EXECUTABLE)
    message(STATUS "cppcheck found: ${CPPCHECK_EXECUTABLE}")

    # Generate compile_commands.json for cppcheck to use
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    
    # Add a custom target to run cppcheck on all subprojects
    add_custom_target(run_cppcheck
        #To ignore certain folders you can use -i. E.g. "-ifoo", this will skip analysis of source files in the foo folder.
        COMMAND ${CPPCHECK_EXECUTABLE}  --project=${CMAKE_BINARY_DIR}/compile_commands.json
        COMMENT "Running cppcheck static analysis on all subprojects"
    )
else()
    message(WARNING "cppcheck not found; code analysis will not be performed.")
endif()

# Add the subprojects
add_subdirectory(subproject1)
add_subdirectory(subproject2)

