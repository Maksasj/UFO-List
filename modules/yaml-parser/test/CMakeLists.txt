include(gclados)

# Add gclados library
add_library(gclados STATIC IMPORTED)
set_target_properties(gclados PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libgclados.a)

add_executable(yaml-parser-tests ${SRC_FILES} "${CMAKE_CURRENT_SOURCE_DIR}/entry.c")

include_directories(yaml-parser-tests "${PROJECT_SOURCE_DIR}/include/gclados")
target_include_directories(yaml-parser-tests PUBLIC "${PROJECT_SOURCE_DIR}/include/yaml-parser")

target_link_libraries(yaml-parser-tests yaml-parser gclados)

add_test(NAME yaml-parser COMMAND yaml-parser-tests)
