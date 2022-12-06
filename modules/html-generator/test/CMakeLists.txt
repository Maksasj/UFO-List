include(gclados)

# Add gclados library
add_library(gclados STATIC IMPORTED)
set_target_properties(gclados PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libgclados.a)

add_executable(html-generator-tests ${SRC_FILES} "${CMAKE_CURRENT_SOURCE_DIR}/entry.c")

include_directories(html-generator-tests "${PROJECT_SOURCE_DIR}/include/gclados")
target_include_directories(html-generator-tests PUBLIC "${PROJECT_SOURCE_DIR}/include/html-generator")

target_link_libraries(html-generator-tests html-generator gclados)

add_test(NAME HTML_GENERATOR COMMAND html-generator-tests)
