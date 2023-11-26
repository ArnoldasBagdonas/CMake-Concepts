# Define the function to process Markdown files
function(process_markdown_files DIRECTORY)
    message(STATUS "Processing Markdown files in directory: ${DIRECTORY}")
    file(GLOB_RECURSE MARKDOWN_FILES "${DIRECTORY}/*.md")
    foreach(MARKDOWN_FILE ${MARKDOWN_FILES})
        get_filename_component(MARKDOWN_DIR "${MARKDOWN_FILE}" DIRECTORY)
        
        message(STATUS "Processing Markdown file: ${MARKDOWN_FILE}")

        # Render the PlantUML code in the Markdown file to PNG
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E env "PATH=$ENV{PATH}" ${CMAKE_COMMAND} -E chdir ${MARKDOWN_DIR} java -jar /plantuml/plantuml.jar -tpng ${MARKDOWN_FILE}
            OUTPUT_VARIABLE OUTPUT_VARIABLE_NAME
            ERROR_VARIABLE ERROR_VARIABLE_NAME
            RESULT_VARIABLE RESULT_VARIABLE_NAME
        )

        # Check the result of the execute_process command and log it
        if(RESULT_VARIABLE_NAME EQUAL 0)
            message(STATUS "Successfully generated PlantUML diagrams for ${MARKDOWN_FILE}")
        else()
            message(WARNING "Failed to generate PlantUML diagrams for ${MARKDOWN_FILE}")
            message(WARNING "Output:\n${OUTPUT_VARIABLE_NAME}")
            message(WARNING "Error:\n${ERROR_VARIABLE_NAME}")
        endif()
    endforeach()
endfunction()

# Call the function with the project's source directory as the argument
process_markdown_files("${CMAKE_BINARY_DIR}/..")
