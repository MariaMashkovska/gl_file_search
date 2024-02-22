cmake_minimum_required(VERSION 3.17)
project(ciplasplas)

set(CMAKE_CXX_STANDARD 17)

add_library(filesearch STATIC file_search.cpp)

add_executable(ciplasplas main.cpp)
target_link_libraries(ciplasplas PRIVATE filesearch)
