# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.5)

# Set the project name
project(exampleproject VERSION 1.0.1)



# Find Python package (assumes it's required for the project)
find_package(Python REQUIRED)

# Call gen_revision_info.py generator to set the version.

# # Example 1: The most basic integration

# add_custom_target(version ALL
#     DEPENDS ${PROJECT_BINARY_DIR}/generated/version.h
# )

# add_custom_command(
#     COMMAND ${Python_EXECUTABLE} version.py --dir ${PROJECT_BINARY_DIR}/generated
#         --name ${PROJECT_NAME} 
#         --major ${PROJECT_VERSION_MAJOR} 
#         --minor ${PROJECT_VERSION_MINOR} 
#         --patch ${PROJECT_VERSION_PATCH}
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#     OUTPUT  ${PROJECT_BINARY_DIR}/generated/version.cpp
#     DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/version.cpp.in ${CMAKE_CURRENT_SOURCE_DIR}/gen_revision_info.py
# )
# # End of example 1



# Example 2: Invoking a complex generator:

# Set variables for the generator script and its arguments
set(VERSION_GENERATE "version.py")
set(VERSION_GENERATE_DIR ${PROJECT_BINARY_DIR}/generated)
set(VERSION_GENERATE_ARGS --genpattern version.cpp.in --output version.cpp --dir ${VERSION_GENERATE_DIR}
    --name ${PROJECT_NAME}
    --major ${PROJECT_VERSION_MAJOR}
    --minor ${PROJECT_VERSION_MINOR}
    --patch ${PROJECT_VERSION_PATCH}
)

# Display the command that will be executed
message("script execute:'${VERSION_GENERATE} ${VERSION_GENERATE_ARGS}'")

# Execute the generator script with arguments to get the dependencies
execute_process(COMMAND ${Python_EXECUTABLE} ${VERSION_GENERATE} ${VERSION_GENERATE_ARGS} --print-dependencies
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE VERSION_GENERATE_DEPENDENCIES
    RESULT_VARIABLE EXIT_ERROR_CODE
)

# Check if the execution of the script was successful
if (NOT EXIT_ERROR_CODE EQUAL 0)
    message(FATAL_ERROR "EXIT_ERROR_CODE: '${EXIT_ERROR_CODE}'")
else()
    message("VERSION_GENERATE_DEPENDENCIES:'${VERSION_GENERATE_DEPENDENCIES}'")
endif()

# Execute the generator script with arguments to get the outputs
execute_process(COMMAND ${Python_EXECUTABLE} ${VERSION_GENERATE} ${VERSION_GENERATE_ARGS} --print-outputs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE VERSION_GENERATE_OUTPUTS
    RESULT_VARIABLE EXIT_ERROR_CODE
)

# Check if the execution of the script was successful
if (NOT EXIT_ERROR_CODE EQUAL 0)
    message(FATAL_ERROR "EXIT_ERROR_CODE: '${EXIT_ERROR_CODE}'")
else()
    message("VERSION_GENERATE_OUTPUTS:'${VERSION_GENERATE_OUTPUTS}'")
endif()

# Define a custom target "version" that depends on the outputs of the generator script
add_custom_target(version ALL
    DEPENDS ${VERSION_GENERATE_OUTPUTS}
)

# Add a custom command to execute the generator script and generate the outputs
add_custom_command(
    COMMAND ${Python_EXECUTABLE} ${VERSION_GENERATE} ${VERSION_GENERATE_ARGS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT ${VERSION_GENERATE_OUTPUTS}
    DEPENDS ${VERSION_GENERATE_DEPENDENCIES}
)
# End of example 2



# Create the executable target for the project, including the generated version.cpp
add_executable(${PROJECT_NAME} main.cpp ${PROJECT_BINARY_DIR}/generated/version.cpp)

# Include the project source directory for header file search
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

# Create a custom target "file_toucher" that touches the generated version.cpp file
add_custom_target(file_toucher 
    COMMAND ${CMAKE_COMMAND} -E touch_nocreate ${PROJECT_BINARY_DIR}/generated/version.cpp
)

# Add "file_toucher" as a dependency for the project
add_dependencies(${PROJECT_NAME} file_toucher)
