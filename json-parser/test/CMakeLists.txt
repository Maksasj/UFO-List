file(GLOB SRC_FILES *.test.c)

add_executable(json-parserTests ${SRC_FILES})

target_include_directories(json-parserTests PUBLIC "${PROJECT_SOURCE_DIR}/include/json-parser")
target_link_libraries(json-parserTests json-parser)

add_test(NAME Json-parser COMMAND json-parserTests)
