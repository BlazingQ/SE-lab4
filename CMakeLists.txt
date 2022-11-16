cmake_minimum_required(VERSION 2.6)
 
project(vscode_cmake)
set(CMAKE_BUILD_TYPE DEBUG)
set(SRC_LIST main.cpp)
add_executable(result ${SRC_LIST})