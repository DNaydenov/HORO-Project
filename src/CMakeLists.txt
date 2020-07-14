cmake_minimum_required(VERSION 3.16)
project(ProjectHoroBeta)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


add_executable(ProjectHoroBeta main.cpp Dancer.cpp Dance.cpp Horo.cpp UnitTests/HoroTest.cpp)

target_link_libraries(ProjectHoroBeta gtest gtest_main)