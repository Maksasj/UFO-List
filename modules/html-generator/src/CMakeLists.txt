add_library(html-generator STATIC html-generator.c)

target_include_directories(html-generator PUBLIC "${PROJECT_SOURCE_DIR}/include/html-generator")
