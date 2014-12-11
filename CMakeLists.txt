cmake_minimum_required(VERSION 2.8)

project(leetcode)

#add_library()
set(CMAKE_CXX_FLAGS "-std=c++0x")

file(GLOB CPP_FILES "*.cpp")
#file(GLOB_RECURSE SOURCE_HEADERS "*.h")

foreach (_sourcefile ${CPP_FILES})
  get_filename_component(_file ${_sourcefile} NAME_WE)
  set(exefile "${_file}.out")
  add_executable(${exefile} ${_sourcefile})
endforeach(_sourcefile)