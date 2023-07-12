# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.5)

# Set the project name and version
project(exampleproject VERSION 1.0.1)

# Get the latest abbreviated commit hash of the working branch
# Retrieve commit hash and commit message using `git log` command
# Reference: https://jonathanhamberg.com/post/cmake-embedding-git-hash/
execute_process(
    COMMAND git log -1 --format=%H
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE PROJECT_GIT_COMMIT_ID
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND git log -1 --format=%s
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE PROJECT_GIT_COMMIT_STRING
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Check if there are any uncommitted changes using `git diff` command
# Reference: https://remarkablemark.org/blog/2017/10/12/check-git-dirty/
execute_process(
    COMMAND git diff --stat
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE PROJECT_GIT_COMMIT_STATUS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Append "-dirty" to the commit hash if there are uncommitted changes
# Reference: https://stackoverflow.com/questions/19982340/cmake-compare-to-empty-string-with-strequal-failed
if("${PROJECT_GIT_COMMIT_STATUS}" STREQUAL "")
else()
    set(PROJECT_GIT_COMMIT_ID "${PROJECT_GIT_COMMIT_ID}-dirty")
endif()

# Retrieve the Git repository URL
execute_process(
    COMMAND git config --get remote.origin.url
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE PROJECT_GIT_REPOSITORY_URL
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Retrieve the hostname of the build machine
execute_process(
    COMMAND hostname
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE PROJECT_BUILD_MACHINE
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Validate and Test Configuration
message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "PROJECT_VERSION: ${PROJECT_VERSION}")
message(STATUS "PROJECT_GIT_COMMIT_ID: ${PROJECT_GIT_COMMIT_ID}")
message(STATUS "PROJECT_GIT_COMMIT_STRING: ${PROJECT_GIT_COMMIT_STRING}")
message(STATUS "PROJECT_GIT_COMMIT_STATUS: ${PROJECT_GIT_COMMIT_STATUS}")
message(STATUS "PROJECT_GIT_REPOSITORY_URL: ${PROJECT_GIT_REPOSITORY_URL}")
message(STATUS "PROJECT_BUILD_MACHINE: ${PROJECT_BUILD_MACHINE}")


# Call configure files on version.h.in to set the version.
# Uses the standard ${VARIABLE} syntax in the file
configure_file (
    "${PROJECT_SOURCE_DIR}/version.cpp.in"
    "${PROJECT_BINARY_DIR}/version.cpp"
)

# Add an executable
add_executable(${PROJECT_NAME} main.cpp "${PROJECT_BINARY_DIR}/version.cpp")

# Include the directory with the new files,
# this allows the 'version.hpp' file to be used throughout the program
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
