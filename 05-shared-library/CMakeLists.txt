# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the project name
project(exampleproject)

# Add a shared library target named "fruit_library" and specify the source file "fruit.cpp"
add_library(fruit_library SHARED 
    ${PROJECT_SOURCE_DIR}/src/fruit.cpp
)

# Create an alias for the library to be used with the namespace "plants::fruit"
add_library(plants::fruit ALIAS fruit_library)

# Specify the include directories for the "fruit_library" target
target_include_directories(fruit_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# Add an executable target named "exampleproject_binary" and specify the source file "main.cpp"
add_executable(exampleproject_binary 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Link the "exampleproject_binary" target with the "fruit_library" target
target_link_libraries(exampleproject_binary
    PRIVATE 
        plants::fruit
)
