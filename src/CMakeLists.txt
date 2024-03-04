set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(STATION_DIR "${INCLUDE_DIR}/station")
set(
    HEADER_LIST
    ${STATION_DIR}/part.h
    ${STATION_DIR}/ships.h
    ${STATION_DIR}/repairBay.h
    ${STATION_DIR}/station.h
)

set(
    SOURCE_LIST
    part.cpp
    ships.cpp
    repairBay.cpp
    station.cpp
)

add_library(station ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(station PUBLIC ${INCLUDE_DIR})

