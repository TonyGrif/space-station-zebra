cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(space-station VERSION 1.0)

add_subdirectory(station/main)

# Should make optional
add_subdirectory(station/test)