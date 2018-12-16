cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

# program

# program test

# ex
ex(NUMBER 5.1 FILES ex.5.1.cpp)

# ex test
test(TARGET ex.5.1)
