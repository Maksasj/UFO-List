file(GLOB SRC_FILES *.test.c)

add_executable(moduleTests ${SRC_FILES})

target_include_directories(moduleTests PUBLIC "${PROJECT_SOURCE_DIR}/include/module")
target_link_libraries(moduleTests module)

add_test(NAME Module COMMAND moduleTests)
