cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

program(dummy dummy.cpp)
coveralls_upload(program.dummy) # program doesn't matter
