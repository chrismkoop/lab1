cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

project(Lab1)

add_executable(
 Lab1
 src/lab1.cpp
 src/rand.h
)

target_link_libraries(Lab1 sfml-graphics)

if (WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(TARGET Lab1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Lab1> $<TARGET_FILE_DIR:Lab1> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Lab1)
