enable_testing()

# Should move to a git submodule soon
include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

set(TESTS
  cpp/main.cpp
  cpp/test_station.cpp
  cpp/test_repairBay.cpp
  cpp/test_ship.cpp
  cpp/test_parts.cpp
)

add_executable(test_${PROJECT_NAME} ${TESTS})

target_link_libraries(
    test_${PROJECT_NAME}
    GTest::gtest_main
    station
    )

gtest_discover_tests(test_${PROJECT_NAME})