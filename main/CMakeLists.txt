add_executable(main main.c)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include/module")
target_link_libraries(main module)
