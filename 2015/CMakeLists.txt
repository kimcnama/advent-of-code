cmake_minimum_required (VERSION 3.8)

set(This 2015)

############################ Day1  ######################################
set(Headers2015Day1
        2015/inc/day1/apartment_floors.h
        )
set(Sources2015Day1
        2015/src/day1/apartment_floors.cpp
        )
add_library(2015Day1 STATIC ${Headers2015Day1} ${Sources2015Day1})

############################ Day2  ######################################
set(Headers2015Day2
        2015/inc/day2/wrapping_order.h
        2015/inc/day2/gift_wrap_dim.h
        2015/inc/day2/gift_ribbon_wrap.h
        2015/inc/day2/wrapping_order_ribbon.h
        )
set(Sources2015Day2
        2015/src/day2/gift_wrap_dim.cpp
        2015/src/day2/wrapping_order.cpp
        2015/src/day2/gift_ribbon_wrap.cpp
        2015/src/day2/wrapping_order_ribbon.cpp
        )
add_library(2015Day2 STATIC ${Headers2015Day2} ${Sources2015Day2})

############################ Day3  ######################################
set(Headers2015Day3
        2015/inc/day3/grid_traverser.h
        2015/inc/day3/grid_traverser_sub.h
        2015/inc/day3/elf_manager.h
        )
set(Sources2015Day3
        2015/src/day3/grid_traverser.cpp
        2015/src/day3/elf_manager.cpp
        2015/src/day3/grid_traverser_sub.cpp
        )
add_library(2015Day3 STATIC ${Headers2015Day3} ${Sources2015Day3})

############################ Day4  ######################################
set(Headers2015Day4
        2015/inc/day4/md5_wrapper.h
        2015/inc/day4/advent_coin_miner.h
        )
set(Sources2015Day4
        2015/src/day4/md5_wrapper.cpp
        2015/src/day4/advent_coint_miner.cpp
        )
add_library(2015Day4 STATIC ${Headers2015Day4} ${Sources2015Day4})
target_link_libraries(2015Day4 ${CryptoLib})

############################ Day5  ######################################
set(Headers2015Day5
        2015/inc/day5/naughty_nice_string.h
        2015/inc/day5/naughty_nice_string_part2.h
        )
set(Sources2015Day5
        2015/src/day5/naughty_nice_string.cpp
        2015/src/day5/naughty_nice_string_part2.cpp
        )
add_library(2015Day5 STATIC ${Headers2015Day5} ${Sources2015Day5})

############################ Day6  ######################################
set(Headers2015Day6
        2015/inc/day6/light_grid.h
        2015/inc/day6/intensity_light_grid.h
        )
set(Sources2015Day6
        2015/src/day6/light_grid.cpp
        2015/src/day6/intensity_light_grid.cpp
        )
add_library(2015Day6 STATIC ${Headers2015Day6} ${Sources2015Day6})

############################ Day7  ######################################
set(Headers2015Day7
        2015/inc/day7/wire.h
        2015/inc/day7/wire_manager.h
        )
set(Sources2015Day7
        2015/src/day7/wire.cpp
        2015/src/day7/wire_manager.cpp
        )
add_library(2015Day7 STATIC ${Headers2015Day7} ${Sources2015Day7})

############################ Day8  ######################################
set(Headers2015Day8
        2015/inc/day8/character_memory_service.h
        2015/inc/day8/reverse_encoder.h)
set(Sources2015Day8
        2015/src/day8/character_memory_service.cpp
        2015/src/day8/reverse_encoder.cpp)
add_library(2015Day8 STATIC ${Headers2015Day8} ${Sources2015Day8})

############################ Day9  ######################################
set(Headers2015Day9
        2015/inc/day9/directed_graph.h
        2015/inc/day9/path_finder.h)
set(Sources2015Day9
        2015/src/day9/directed_graph.cpp
        2015/src/day9/path_finder.cpp)
add_library(2015Day9 STATIC ${Headers2015Day9} ${Sources2015Day9})

############################ Day10  ######################################
set(Headers2015Day10
        2015/inc/day10/look_say_encoder.h
        )
set(Sources2015Day10
        2015/src/day10/look_say_encoder.cpp)
add_library(2015Day10 STATIC ${Headers2015Day10} ${Sources2015Day10})