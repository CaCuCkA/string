cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME LabString)
set(LIB_NAME my_string)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME} LANGUAGES CXX)

add_subdirectory(library)
add_subdirectory(tests)
