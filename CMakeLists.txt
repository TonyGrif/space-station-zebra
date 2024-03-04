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

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(TEST_STATION "Build the unit tests for the station library." ON)

add_subdirectory(src)

add_executable(
    station-zebra 
    main.cpp
)
target_link_libraries(station-zebra PRIVATE station)

if(TEST_STATION)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
