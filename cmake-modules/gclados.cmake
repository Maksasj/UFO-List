file(GLOB SRC_FILES *.test.c)

find_program(GCLADOS "gclados")
if(GCLADOS)
    add_custom_command(
            OUTPUT ./entry.c
            COMMAND gclados generate ./*.test.c --output ./entry.c
            DEPENDS ${SRC_FILES}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()
