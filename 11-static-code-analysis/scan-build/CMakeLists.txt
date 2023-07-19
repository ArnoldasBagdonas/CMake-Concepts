# Set the minimum required version of CMake
cmake_minimum_required (VERSION 3.5)

# Set the project name
project(exampleproject)

# Define a function to add a subproject
function(add_subproject name)
    add_subdirectory(${name})
    add_custom_target(${name}-scan-build
    COMMAND bash ${CMAKE_SOURCE_DIR}/scripts/run_scan_build.sh ${CMAKE_CURRENT_SOURCE_DIR}/${name}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running scan-build for the subproject..."
)
endfunction()

# Add the subprojects
add_subproject(subproject1)
add_subproject(subproject2)
