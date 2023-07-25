# CMakeLists.txt

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.14)

# Project Name
project(exampleproject)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include GoogleTest using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Option for the Build Name
# Set the default value for BUILD_NAME as the CMake build type
OPTION(BUILD_NAME "${CMAKE_BUILD_TYPE}")

# Sanitizer Options
# If the CMake build type is "Debug" and the compiler is GNU or Clang, configure the sanitizers accordingly.
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang") AND (CMAKE_BUILD_TYPE MATCHES "Debug"))

  # Option for Code Coverage
  OPTION(ENABLE_COVERAGE "Use gcc flags to enable Coverage tests" OFF)
  if(ENABLE_COVERAGE)
    message("* Adding correct flags to enable code coverage through a build type")
    add_compile_options(--coverage)
    add_link_options(--coverage)
  endif()

  # Configure the appropriate sanitizer flags based on the selected BUILD_NAME
  string(TOUPPER ${BUILD_NAME} SANITIZER_ID)

  if(SANITIZER_ID STREQUAL "ADDRESSSANITIZER")
    message("* Adding correct flags to enable AddressSanitizer through a build type")
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
    # add_compile_options(-fno-omit-frame-pointer)
    # add_compile_options(-fno-omit-frame-pointer)
  endif()


  if(SANITIZER_ID STREQUAL "LEAKSANITIZER")
    message("* Adding correct flags to enable LeakSanitizer through a build type")
    add_compile_options(-fsanitize=leak)
    add_link_options(-fsanitize=leak)
  endif()

  if(SANITIZER_ID STREQUAL "THREADSANITIZER")
    message("* Adding correct flags to enable ThreadSanitizer through a build type")
    add_compile_options(-fsanitize=thread)
    add_link_options(-fsanitize=thread)
  endif()

  if(SANITIZER_ID STREQUAL "MEMORYSANITIZER")
    message("* Adding correct flags to enable MemorySanitizer through a build type")
    add_compile_options(-fsanitize=memory)
    add_link_options(-fsanitize=memory)
    add_compile_options(-fno-omit-frame-pointer)
    add_link_options(-fno-omit-frame-pointer)
  endif()

  if(SANITIZER_ID STREQUAL "UNDEFINEDBEHAVIORSANITIZER")
    message("* Adding correct flags to enable UndefinedBehaviorSanitizer through a build type")
    add_compile_options(-fsanitize=undefined)
    add_compile_options(-fsanitize=shift)
    add_compile_options(-fsanitize=integer-divide-by-zero)
    add_compile_options(-fsanitize=unreachable)
    add_compile_options(-fsanitize=vla-bound)
    add_compile_options(-fsanitize=null)
    add_compile_options(-fsanitize=return)
    add_compile_options(-fsanitize=signed-integer-overflow)
    add_compile_options(-fsanitize=bounds)
    add_compile_options(-fsanitize=alignment)
    #add_compile_options(-fsanitize=object-size)
    add_compile_options(-fsanitize=float-divide-by-zero)
    add_compile_options(-fsanitize=float-cast-overflow)
    add_compile_options(-fsanitize=nonnull-attribute)
    add_compile_options(-fsanitize=returns-nonnull-attribute)
    add_compile_options(-fsanitize=bool)
    add_compile_options(-fsanitize=enum)
    add_compile_options(-fsanitize=vptr)
    add_link_options(-fsanitize=undefined)
    add_link_options(-fsanitize=shift)
    add_link_options(-fsanitize=integer-divide-by-zero)
    add_link_options(-fsanitize=unreachable)
    add_link_options(-fsanitize=vla-bound)
    add_link_options(-fsanitize=null)
    add_link_options(-fsanitize=return)
    add_link_options(-fsanitize=signed-integer-overflow)
    add_link_options(-fsanitize=bounds)
    add_link_options(-fsanitize=alignment)
    #add_link_options(-fsanitize=object-size)
    add_link_options(-fsanitize=float-divide-by-zero)
    add_link_options(-fsanitize=float-cast-overflow)
    add_link_options(-fsanitize=nonnull-attribute)
    add_link_options(-fsanitize=returns-nonnull-attribute)
    add_link_options(-fsanitize=bool)
    add_link_options(-fsanitize=enum)
    add_link_options(-fsanitize=vptr)
  endif()

  if(SANITIZER_ID STREQUAL "VALGRIND")
    message("* Adding correct flags to enable Valgrind through a build type")
    set(VALGRIND_OPTIONS --error-exitcode=1 --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --gen-suppressions=all)
  endif()


endif()

# Configure CDash
message("* Configuring CDash(${BUILD_NAME})")
add_custom_target(submit_to_cdash
  COMMAND +${CMAKE_CTEST_COMMAND} -S "${CMAKE_SOURCE_DIR}/ci_pipeline.cmake" -DBUILD_NAME=${BUILD_NAME} -DENABLE_COVERAGE=${ENABLE_COVERAGE}
  COMMENT "Submitting to CDash(${BUILD_NAME})"
)



# Create a static library target named "addressSanitizerDefects"
add_library(lib_addressSanitizerDefects STATIC 
    ${PROJECT_SOURCE_DIR}/src/addressSanitizerDefects.cpp
)

# Specify the include directories for the "addressSanitizerDefects" target
target_include_directories(lib_addressSanitizerDefects
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


# Create a static library target named "threadSanitizerDefects"
add_library(lib_threadSanitizerDefects STATIC 
    ${PROJECT_SOURCE_DIR}/src/threadSanitizerDefects.cpp
)

# Specify the include directories for the "threadSanitizerDefects" target
target_include_directories(lib_threadSanitizerDefects
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


# Create a static library target named "undefinedBehaviorSanitizerDefects"
add_library(lib_undefinedBehaviorSanitizerDefects STATIC 
    ${PROJECT_SOURCE_DIR}/src/undefinedBehaviorSanitizerDefects.cpp
)

# Specify the include directories for the "undefinedBehaviorSanitizerDefects" target
target_include_directories(lib_undefinedBehaviorSanitizerDefects
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


# Create an executable target named "allDefects"
add_executable(allDefects
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Link the "vegetable_library" target to the "allDefects" target
target_link_libraries(allDefects
    PRIVATE 
    lib_addressSanitizerDefects
    lib_threadSanitizerDefects
    lib_undefinedBehaviorSanitizerDefects
)

# Include CTest and enable testing
include(CTest)
enable_testing()


# Create the test_addressSanitizerDefects executable and link to GoogleTest
add_executable(test_addressSanitizerDefects
  ${PROJECT_SOURCE_DIR}/test/test_addressSanitizerDefects.cpp
)
target_link_libraries(test_addressSanitizerDefects
  GTest::gmock
  GTest::gtest_main
  lib_addressSanitizerDefects
)
# Include directories for test_binary
target_include_directories(test_addressSanitizerDefects
  PUBLIC ${PROJECT_SOURCE_DIR}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)


# Create the test_threadSanitizerDefects executable and link to GoogleTest
add_executable(test_threadSanitizerDefects
  ${PROJECT_SOURCE_DIR}/test/test_threadSanitizerDefects.cpp
)
target_link_libraries(test_threadSanitizerDefects
  GTest::gmock
  GTest::gtest_main
  lib_threadSanitizerDefects
)
# Include directories for test_binary
target_include_directories(test_threadSanitizerDefects
  PUBLIC ${PROJECT_SOURCE_DIR}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)


# Create the test_threadSanitizerDefects executable and link to GoogleTest
add_executable(test_undefinedBehaviorSanitizerDefects
  ${PROJECT_SOURCE_DIR}/test/test_undefinedBehaviorSanitizerDefects.cpp
)
target_link_libraries(test_undefinedBehaviorSanitizerDefects
  GTest::gmock
  GTest::gtest_main
  lib_undefinedBehaviorSanitizerDefects
)
# Include directories for test_binary
target_include_directories(test_undefinedBehaviorSanitizerDefects
  PUBLIC ${PROJECT_SOURCE_DIR}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)



# Discover GoogleTest tests
include(GoogleTest)
gtest_discover_tests(test_addressSanitizerDefects)
gtest_discover_tests(test_threadSanitizerDefects)
gtest_discover_tests(test_undefinedBehaviorSanitizerDefects)

# Run tests with Valgrind
if(SANITIZER_ID STREQUAL "VALGRIND")
  add_test(NAME memchecked_test_addressSanitizerDefects
         COMMAND valgrind ${VALGRIND_OPTIONS} $<TARGET_FILE:test_addressSanitizerDefects>)

  add_test(NAME memchecked_test_threadSanitizerDefects
         COMMAND valgrind ${VALGRIND_OPTIONS} $<TARGET_FILE:test_threadSanitizerDefects>)

  add_test(NAME memchecked_test_undefinedBehaviorSanitizerDefects
         COMMAND valgrind ${VALGRIND_OPTIONS} $<TARGET_FILE:test_undefinedBehaviorSanitizerDefects>)
endif()
