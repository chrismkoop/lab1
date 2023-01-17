cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Lab1)

add_executable(
 Lab1
 src/lab1.cpp
)

find_package(SFML 2.5.1 COMPONENTS graphics system window audio)

target_link_libraries(Lab1 sfml-graphics)
