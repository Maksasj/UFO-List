add_library(chashmap STATIC chashmap.c)

target_include_directories(chashmap PUBLIC "${PROJECT_SOURCE_DIR}/include/chashmap")
