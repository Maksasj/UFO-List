file(GLOB SRC_FILES *.c)

add_library(yaml-parser STATIC ${SRC_FILES})

target_include_directories(yaml-parser PUBLIC "${PROJECT_SOURCE_DIR}/include/yaml-parser")