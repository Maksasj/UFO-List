cmake_minimum_required(VERSION 3.20)

project(UFOList VERSION 1.0)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake-modules")

enable_testing()

add_subdirectory(main)

add_subdirectory(modules)
