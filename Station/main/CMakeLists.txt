add_executable(${PROJECT_NAME} cpp/main.cpp)

set(SOURCES
    cpp/station.cpp
    cpp/repairBay.cpp
    cpp/ships.cpp
    cpp/parts.cpp)

add_library(Station ${SOURCES})

target_link_libraries(${PROJECT_NAME} Station)