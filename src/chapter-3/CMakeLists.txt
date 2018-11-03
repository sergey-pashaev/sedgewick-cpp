cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

ex(3.1 ex.3.1.cpp)
ex(3.2 ex.3.2.cpp)
ex(3.3 ex.3.3.cpp)

test_runnable(ex.3.1)
test_runnable(ex.3.2)
test_runnable(ex.3.3)
