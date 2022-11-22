add_library(module STATIC json-parser.c)

target_include_directories(module PUBLIC "${PROJECT_SOURCE_DIR}/include/json-parser")
