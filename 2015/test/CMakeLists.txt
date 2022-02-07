cmake_minimum_required (VERSION 3.8)

set(This ExampleTests)

set(Sources day1/tests.cpp day2/tests.cpp day3/tests.cpp day4/md5tests.cpp day4/miner_logic.cpp day4/miner.cpp day5/naught_nice_tests.cpp day5/naughty_nice_tests_part2.cpp day6/light_grid_tests.cpp day6/intensity_light_grid_tests.cpp day7/wire_tests.cpp day7/wire_manager_tests.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC gtest_main AdventOfCode)

add_test(NAME ${This}
        COMMAND ${This}
        )
