cmake_minimum_required(VERSION 2.8.9)
project (main)
add_executable(main cost.cpp main.cpp)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

add_custom_command(TARGET main POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:main>"
     "../$<CONFIGURATION>/$<TARGET_FILE_NAME:main>" 
  COMMENT "Copying to output directory")
