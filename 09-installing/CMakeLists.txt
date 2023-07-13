# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the project name
project(exampleproject)

############################################################
# Installation & built settings
############################################################

# Enable building with the install RPATH
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

# Specify the installation RPATH (Runtime Search Path)
# The installed binaries will search for libraries in this path
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# Use the linker's search path for the RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


############################################################
# Create a library
############################################################

# Add a shared library target called "fruit_library"
add_library(fruit_library SHARED 
    ${PROJECT_SOURCE_DIR}/src/fruit.cpp
)

# Add the include directory to the library's include paths
target_include_directories(fruit_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
############################################################

# Add an executable target called "exampleproject_inst_bin"
add_executable(exampleproject_inst_bin 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Link the "fruit_library" with the executable
target_link_libraries(exampleproject_inst_bin
    PRIVATE 
        fruit_library
)

############################################################
# Install
############################################################

# Install the "exampleproject_inst_bin" binary to the "bin" directory
install(TARGETS exampleproject_inst_bin
    DESTINATION bin
    PERMISSIONS
        OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE
)

# Install the "fruit_library" shared library to the "lib" directory
install(TARGETS fruit_library
    LIBRARY DESTINATION lib
    PERMISSIONS
        OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE
)

# Install the contents of the "include" directory to the "include" directory
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
    PERMISSIONS
        OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ
)

# Install the "exampleproject_inst_bin.conf" file to the "etc" directory
install(FILES exampleproject_inst_bin.conf
    DESTINATION etc
    PERMISSIONS
        OWNER_READ OWNER_WRITE
        GROUP_READ
        WORLD_READ
)

# Add the uninstall target
if(NOT TARGET uninstall)
    # Restrict variable replacement to references of the form @VAR@.
    # This is useful for configuring scripts that use ${VAR} syntax.
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()