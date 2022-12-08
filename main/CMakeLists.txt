add_executable(main main.c)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include/html-generator")
target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include/yaml-parser")
target_link_libraries(main html-generator)
target_link_libraries(main yaml-parser)
