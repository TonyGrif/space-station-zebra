cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SpaceStation VERSION 1.0)

enable_testing()

add_subdirectory(Station)
add_subdirectory(test)