# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the project name
project(exampleproject)

# Create a static library target named "vegetable_library"
add_library(vegetable_library STATIC 
    ${PROJECT_SOURCE_DIR}/src/vegetable.cpp
)

# Specify the include directories for the "vegetable_library" target
target_include_directories(vegetable_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# Create an executable target named "exampleproject_binary"
add_executable(exampleproject_binary 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Link the "vegetable_library" target to the "exampleproject_binary" target
target_link_libraries(exampleproject_binary 
    PRIVATE 
        vegetable_library
)
