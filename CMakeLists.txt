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
        )

set(TestDirs 2015/test)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(${TestDirs})
