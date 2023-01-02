add_executable(${PROJECT_NAME} cpp/main.cpp)

set(SOURCES
    cpp/station.cpp
    cpp/repairBay.cpp
    cpp/ships.cpp
    cpp/part.cpp)

add_library(station ${SOURCES})

target_link_libraries(${PROJECT_NAME} station)