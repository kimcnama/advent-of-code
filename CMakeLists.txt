cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(This AdventOfCode)

project(${This})

enable_testing()

add_subdirectory(googletest)

set(Headers
        2015/inc/day1/apartment_floors.h
        )

set(Sources
        2015/src/day1/apartment_floors.cpp
        2015/inc/day2/gift_wrap_dim.h 2015/src/day2/gift_wrap_dim.cpp 2015/inc/day2/wrapping_order.h 2015/src/day2/wrapping_order.cpp 2015/inc/day2/gift_ribbon_wrap.h 2015/src/day2/gift_ribbon_wrap.cpp 2015/inc/day2/wrapping_order_ribbon.h 2015/src/day2/wrapping_order_ribbon.cpp 2015/inc/day3/grid_traverser.h 2015/src/day3/grid_traverser.cpp 2015/inc/day3/grid_traverser_sub.h 2015/src/day3/grid_traverser_sub.cpp 2015/inc/day3/elf_manager.h 2015/src/day3/elf_manager.cpp)

set(TestDirs 2015/test)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(${TestDirs})
