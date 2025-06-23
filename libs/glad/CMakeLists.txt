cmake_minimum_required(VERSION 3.26.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Glad)

add_library(glad include/glad/gl.h src/gl.c)
target_include_directories(glad PUBLIC include/)