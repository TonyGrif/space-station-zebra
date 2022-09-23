add_executable(station_test 
  test_station.cpp 
  test_repairBay.cpp
  test_ship.cpp
  test_parts.cpp)

target_link_libraries(station_test
 PRIVATE
  GTest::GTest
  station)

include(GoogleTest)
gtest_discover_tests(station_test)
