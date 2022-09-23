add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(station)

target_link_libraries(${PROJECT_NAME} station)

set(EXECUTABLE_OUTPUT_PATH ..)