cmake_minimum_required(VERSION 3.16)

project(UniqueMaxN CXX)

find_package(GTest REQUIRED)
find_package(Boost 
             COMPONENTS program_options filesystem REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(tools)
