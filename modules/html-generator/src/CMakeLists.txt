file(GLOB SRC_FILES *.c)

add_library(html-generator STATIC ${SRC_FILES})

target_include_directories(html-generator PUBLIC "${PROJECT_SOURCE_DIR}/include/html-generator")
