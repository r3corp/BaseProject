enable_testing()

file(GLOB TEST_SOURCES unit/*.cpp)
add_executable(tests ${TEST_SOURCES})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(tests GTest::gtest GTest::gtest_main pthread)

add_test(NAME AllTests COMMAND tests)
