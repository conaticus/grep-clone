cmake_minimum_required(VERSION 3.13)
project(grep)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/main.cpp src/PatternMatcher.cpp src/PatternParser)
add_executable(main ${SOURCE_FILES})