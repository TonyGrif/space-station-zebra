cmake_minimum_required(VERSION 3.9...3.28)
project(
    space-station-zerbra
    VERSION 1.0
    DESCRIPTION "Simulate the runnings of a space repair station"
    LANGUAGES CXX
)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

add_executable(
    station 
    station/main/cpp/main.cpp
    station/main/cpp/part.cpp
    station/main/cpp/ships.cpp
    station/main/cpp/repairBay.cpp
    station/main/cpp/station.cpp
)
