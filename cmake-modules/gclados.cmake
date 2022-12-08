file(GLOB SRC_FILES *.test.c)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/entry.c
    COMMAND gclados generate ${CMAKE_CURRENT_SOURCE_DIR}/*.test.c --output ${CMAKE_CURRENT_SOURCE_DIR}/entry.c
    DEPENDS ${SRC_FILES}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
