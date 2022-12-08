include(gclados)

# Add gclados library
add_library(gclados STATIC IMPORTED)
set_target_properties(gclados PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libgclados.a)

add_executable(chashmap-tests ${SRC_FILES} "${CMAKE_CURRENT_SOURCE_DIR}/entry.c")

include_directories(chashmap-tests "${PROJECT_SOURCE_DIR}/include/gclados")
target_include_directories(chashmap-tests PUBLIC "${PROJECT_SOURCE_DIR}/include/chashmap")

target_link_libraries(chashmap-tests chashmap gclados)

add_test(NAME CHASHMAP COMMAND chashmap-tests)
