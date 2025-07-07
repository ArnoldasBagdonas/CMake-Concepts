# Find the clang-format executable
find_program(CLANG_FORMAT_EXECUTABLE clang-format)
if (NOT CLANG_FORMAT_EXECUTABLE)
    message(FATAL_ERROR "clang-format not found. Please install clang-format.")
endif()

# Set the file extensions to be checked by clang-format
set(CLANG_FORMAT_CXX_FILE_EXTENSIONS ${CLANG_FORMAT_CXX_FILE_EXTENSIONS} *.cpp *.h *.cxx *.hxx *.hpp *.cc *.ipp)

# Get a list of source files with the specified file extensions
file(GLOB_RECURSE CLANG_FORMAT_SOURCE_FILES ${CLANG_FORMAT_CXX_FILE_EXTENSIONS})

# Specify patterns to exclude certain files or directories from formatting
set(CLANG_FORMAT_EXCLUDE_PATTERNS
    "/CMakeFiles/"
    "cmake"
    "build/"
)

# Exclude files matching the specified patterns from the list of source files
foreach (SOURCE_FILE ${CLANG_FORMAT_SOURCE_FILES})
    foreach (EXCLUDE_PATTERN ${CLANG_FORMAT_EXCLUDE_PATTERNS})
        string(FIND "${SOURCE_FILE}" "${EXCLUDE_PATTERN}" EXCLUDED_PATTERN_FOUND)
        if (NOT ${EXCLUDED_PATTERN_FOUND} EQUAL -1)
            list(REMOVE_ITEM CLANG_FORMAT_SOURCE_FILES ${SOURCE_FILE})
            break()  # No need to check further if we found a match
        endif ()
    endforeach ()
endforeach ()

# Output the list of source files after excluding
message("clang-format source files: ${CLANG_FORMAT_SOURCE_FILES}")

# Create a custom target 'format' to run clang-format on the source files and apply formatting changes
add_custom_target(format
    COMMAND ${CLANG_FORMAT_EXECUTABLE} -style=LLVM -i ${CLANG_FORMAT_SOURCE_FILES}
    COMMENT "Running clang-format on all source files..."
)

# Create a custom target 'format-check' to check if source files match the expected style
add_custom_target(format-check
    COMMAND ${CLANG_FORMAT_EXECUTABLE} -style=LLVM --dry-run ${CLANG_FORMAT_SOURCE_FILES}
    #COMMAND ${CLANG_FORMAT_EXECUTABLE} -style=LLVM --dry-run -Werror ${CLANG_FORMAT_SOURCE_FILES}
    COMMENT "Checking formatting of all source files..."
)
