file(GLOB SRC_FILES *.c)

add_library(css-generator STATIC ${SRC_FILES})

target_include_directories(css-generator PUBLIC "${PROJECT_SOURCE_DIR}/include/css-generator")