cmake_minimum_required(VERSION 2.8)

project(leetcode)

#add_library()
set(CMAKE_CXX_FLAGS "-std=c++0x -g")

file(GLOB CPP_FILES "*.cpp")
#file(GLOB SOURCE_HEADERS "*.h")
set(ALL_SOURCES ${CPP_FILES})
#list(REMOVE_ITEM ALL_SOURCES utils.cpp)

foreach (_sourcefile ${ALL_SOURCES})
  get_filename_component(_file ${_sourcefile} NAME_WE)
  if(NOT ${_file} STREQUAL "utils")  #excluding create output file for utils.cpp
    set(exefile "${_file}.out")
    add_executable(${exefile} ${_sourcefile} utils.cpp)
  endif(NOT ${_file} STREQUAL "utils")
endforeach(_sourcefile)