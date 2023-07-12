# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the project name
project(exampleproject)

# Find the Boost library with a minimum version of 1.46.1 and required components 'filesystem' and 'system'
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# Check if Boost was found
if(Boost_FOUND)
    message("Boost found")
else()
    # Display a fatal error message if Boost was not found
    message(FATAL_ERROR "Cannot find Boost")
endif()

# Create an executable named 'exampleproject_binary' from the source file 'main.cpp'
add_executable(exampleproject_binary main.cpp)

# Link the Boost 'filesystem' library to the 'exampleproject_binary' executable
target_link_libraries(exampleproject_binary
    PRIVATE
        Boost::filesystem
)
