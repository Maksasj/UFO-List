file(GLOB SRC_FILES *.c)

add_library(chashmap STATIC ${SRC_FILES})

target_include_directories(chashmap PUBLIC "${PROJECT_SOURCE_DIR}/include/chashmap")