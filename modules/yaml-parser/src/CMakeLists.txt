add_library(yaml-parser STATIC yaml-parser.c)

target_include_directories(yaml-parser PUBLIC "${PROJECT_SOURCE_DIR}/include/yaml-parser")
