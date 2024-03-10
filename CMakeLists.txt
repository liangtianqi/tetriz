cmake_minimum_required(VERSION 3.22)
project(tetriz)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")

aux_source_directory(. src)
add_executable(tetriz ${src})