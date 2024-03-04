include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(
    TEST_LIST
    test_parts.cpp
    test_ship.cpp
    test_repairBay.cpp
    test_station.cpp
)

add_executable(station_test main.cpp ${TEST_LIST})
target_link_libraries(station_test GTest::gtest_main station)
include(GoogleTest)
gtest_discover_tests(station_test)
