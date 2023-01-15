file(GLOB SRC_FILES *.c)

add_executable(main ${SRC_FILES})

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include/html-generator")
target_link_libraries(main html-generator)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include/chashmap")
target_link_libraries(main chashmap)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include/yaml-parser")
target_link_libraries(main yaml-parser)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include/css-generator")
target_link_libraries(main css-generator)
