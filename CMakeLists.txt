cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(This AdventOfCode)

project(${This})

enable_testing()

add_subdirectory(googletest)

include(2015/CMakeLists.txt)

set(Headers
        2015/inc/day1/apartment_floors.h
        2015/inc/day4/md5_wrapper.h
        2015/inc/day2/wrapping_order.h
        2015/inc/day2/gift_wrap_dim.h
        2015/inc/day4/advent_coin_miner.h
        2015/inc/day5/naughty_nice_string.h
        2015/inc/day5/naughty_nice_string_part2.h
        2015/inc/day2/gift_ribbon_wrap.h
        2015/inc/day2/wrapping_order_ribbon.h
        2015/inc/day3/grid_traverser.h
        2015/inc/day3/grid_traverser_sub.h
        2015/inc/day3/elf_manager.h
        2015/inc/day6/light_grid.h
        2015/inc/day6/intensity_light_grid.h
        2015/inc/day7/wire.h
        2015/inc/day7/wire_manager.h
        2015/inc/day8/character_memory_service.h)

set(Sources
        2015/src/day1/apartment_floors.cpp
        2015/src/day2/gift_wrap_dim.cpp
        2015/src/day2/wrapping_order.cpp
        2015/src/day2/gift_ribbon_wrap.cpp
        2015/src/day2/wrapping_order_ribbon.cpp
        2015/src/day3/grid_traverser.cpp
        2015/src/day3/elf_manager.cpp
        2015/src/day4/md5_wrapper.cpp
        2015/src/day3/grid_traverser_sub.cpp
        2015/src/day4/advent_coint_miner.cpp
        2015/src/day5/naughty_nice_string.cpp
        2015/src/day5/naughty_nice_string_part2.cpp
        2015/src/day6/light_grid.cpp
        2015/src/day6/intensity_light_grid.cpp
        2015/src/day7/wire.cpp
        2015/src/day7/wire_manager.cpp
        2015/src/day8/character_memory_service.cpp)

set(TestDirs 2015/test)
set(CryptoLib ${PROJECT_SOURCE_DIR}/2015/lib/mac/chilkat/libDyn/libchilkat_x86_64.dylib)
include_directories(${PROJECT_SOURCE_DIR}/2015/lib/mac/chilkat/inc)

add_library(${This} STATIC ${Headers} ${Sources})

target_link_libraries(${This} ${CryptoLib})

add_subdirectory(${TestDirs})
