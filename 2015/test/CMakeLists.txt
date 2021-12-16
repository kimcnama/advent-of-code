cmake_minimum_required (VERSION 3.8)

set(This ExampleTests)

set(Sources day1/tests.cpp day2/tests.cpp day3/tests.cpp day4/md5tests.cpp day4/miner_logic.cpp day4/miner.cpp day5/naught_nice_tests.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC gtest_main AdventOfCode)

add_test(NAME ${This}
        COMMAND ${This}
        )
