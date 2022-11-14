add_library(module STATIC module.c)

target_include_directories(module PUBLIC "${PROJECT_SOURCE_DIR}/include/module")
