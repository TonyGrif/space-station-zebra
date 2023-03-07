set(sources
    station/main/cpp/part.cpp
    station/main/cpp/repairBay.cpp
    station/main/cpp/ships.cpp
    station/main/cpp/station.cpp
)

set(exe_sources
    station/main/cpp/main.cpp
	${sources}
)

set(headers
    station/main/headers/part.h
    station/main/headers/repairBay.h
    station/main/headers/ships.h
    station/main/headers/station.h
)

set(test_sources
    cpp/main.cpp
    cpp/test_parts.cpp
    cpp/test_repairBay.cpp
    cpp/test_ship.cpp
    cpp/test_station.cpp
)