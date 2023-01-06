set(SOURCES
    cpp/station.cpp
    cpp/repairBay.cpp
    cpp/ships.cpp
    cpp/part.cpp)

set(EXE_SOURCES
    cpp/main.cpp
    ${SOURCES}
)

set(HEADERS
    headers/station.h
    headers/repairBay.h
    headers/ships.h
    headers/part.h
)

if(BUILD_EXECUTABLE)
    add_executable(${PROJECT_NAME} ${EXE_SOURCES})

    if(ENABLE_UNIT_TESTING)
        add_library(${PROJECT_NAME}_lib ${HEADERS} ${SOURCES})
    endif()

elseif(BUILD_HEADERS_ONLY)
    add_library(${PROJECT_NAME} INTERFACE)

else()
    add_library(
        ${PROJECT_NAME}
        ${HEADERS}
        ${SOURCES}
    )
endif()

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}"
)
if(BUILD_EXECUTABLE AND ENABLE_UNIT_TESTING)
    set_target_properties(
        ${PROJECT_NAME}_lib
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
        OUTPUT_NAME ${PROJECT_NAME}
    )
endif()