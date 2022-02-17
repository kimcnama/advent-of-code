cmake_minimum_required (VERSION 3.8)

set(This ExampleTests)

set(Sources
        day1/tests.cpp
        day2/tests.cpp
        day3/tests.cpp
        day4/md5tests.cpp
        day4/miner_logic.cpp
        day4/miner.cpp
        day5/naught_nice_tests.cpp
        day5/naughty_nice_tests_part2.cpp
        day6/light_grid_tests.cpp
        day6/intensity_light_grid_tests.cpp
        day7/wire_tests.cpp
        day7/wire_manager_tests.cpp day8/character_memory_service_tests.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC gtest_main AdventOfCode)

add_test(NAME ${This}
        COMMAND ${This}
        )

############################ Day1  ######################################
set(Day1 2015Day1Test)
set(SourcesDay1 day1/tests.cpp)

add_executable(${Day1} ${SourcesDay1})
target_link_libraries(${Day1} PUBLIC gtest_main 2015Day1)

add_test(NAME ${Day1}
        COMMAND ${Day1}
        )

############################ Day2  ######################################
set(Day2 2015Day2Test)
set(SourcesDay2 day2/tests.cpp)

add_executable(${Day2} ${SourcesDay2})
target_link_libraries(${Day2} PUBLIC gtest_main 2015Day2)

add_test(NAME ${Day2}
        COMMAND ${Day2}
        )

############################ Day3  ######################################
set(Day3 2015Day3Test)
set(SourcesDay3 day3/tests.cpp)

add_executable(${Day3} ${SourcesDay3})
target_link_libraries(${Day3} PUBLIC gtest_main 2015Day3)

add_test(NAME ${Day3}
        COMMAND ${Day3}
        )

############################ Day4  ######################################
set(Day4 2015Day4Test)
set(SourcesDay4
        day4/md5tests.cpp
        day4/miner_logic.cpp
        day4/miner.cpp
        )

add_executable(${Day4} ${SourcesDay4})
target_link_libraries(${Day4} PUBLIC gtest_main 2015Day4)

add_test(NAME ${Day4}
        COMMAND ${Day4}
        )

############################ Day5  ######################################
set(Day5 2015Day5Test)
set(SourcesDay5
        day5/naught_nice_tests.cpp
        day5/naughty_nice_tests_part2.cpp
        )

add_executable(${Day5} ${SourcesDay5})
target_link_libraries(${Day5} PUBLIC gtest_main 2015Day5)

add_test(NAME ${Day5}
        COMMAND ${Day5}
        )

############################ Day6  ######################################
set(Day6 2015Day6Test)
set(SourcesDay6
        day6/light_grid_tests.cpp
        day6/intensity_light_grid_tests.cpp
        )

add_executable(${Day6} ${SourcesDay6})
target_link_libraries(${Day6} PUBLIC gtest_main 2015Day6)

add_test(NAME ${Day6}
        COMMAND ${Day6}
        )

############################ Day7  ######################################
set(Day7 2015Day7Test)
set(SourcesDay7
        day7/wire_tests.cpp
        day7/wire_manager_tests.cpp
        )

add_executable(${Day7} ${SourcesDay7})
target_link_libraries(${Day7} PUBLIC gtest_main 2015Day7)

add_test(NAME ${Day7}
        COMMAND ${Day7}
        )

############################ Day8  ######################################
set(Day8 2015Day8Test)
set(SourcesDay8
        day8/character_memory_service_tests.cpp
        day8/reverse_encoder_tests.cpp
        )

add_executable(${Day8} ${SourcesDay8})
target_link_libraries(${Day8} PUBLIC gtest_main 2015Day8)

add_test(NAME ${Day8}
        COMMAND ${Day8}
        )

############################ Day9  ######################################
set(Day9 2015Day9Test)
set(SourcesDay9
        day9/directed_graph_tests.cpp day9/path_finder_tests.cpp)

add_executable(${Day9} ${SourcesDay9})
target_link_libraries(${Day9} PUBLIC gtest_main 2015Day9)

add_test(NAME ${Day9}
        COMMAND ${Day9}
        )

############################ Day10  ######################################
set(Day10 2015Day10Test)
set(SourcesDay10
        day10/look_say_encoder_tests.cpp)

add_executable(${Day10} ${SourcesDay10})
target_link_libraries(${Day10} PUBLIC gtest_main 2015Day10)

add_test(NAME ${Day10}
        COMMAND ${Day10}
        )


