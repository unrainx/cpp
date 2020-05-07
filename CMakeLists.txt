cmake_minimum_required(VERSION 3.10)

project(rstring)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(./src SRC_DIR)

add_executable(a ${SRC_DIR})