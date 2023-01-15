file(GLOB SRC_FILES *.c)

add_library(card-info STATIC ${SRC_FILES})

target_include_directories(card-info PUBLIC "${PROJECT_SOURCE_DIR}/include/card-info")