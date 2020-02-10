cmake_minimum_required(VERSION 2.8.9)
project (main)
add_executable(main classifier.cpp main.cpp)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)
