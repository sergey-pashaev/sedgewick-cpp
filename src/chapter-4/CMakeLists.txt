cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

# program

# program test

# ex
ex(4.1 ex.4.1.cpp)
ex(4.2 ex.4.2.cpp)
ex(4.3 ex.4.3.cpp)
ex(4.4 ex.4.4.cpp)
ex(4.6 ex.4.6.cpp)
ex(4.7 ex.4.7.cpp)
resource(ex.4.9.md)
resource(ex.4.10.md)

# ex test
test_runnable(ex.4.1 10 0.5)
test_runnable(ex.4.2)
test_runnable(ex.4.3)
test_runnable(ex.4.4 100)
test_runnable(ex.4.6)
test_runnable(ex.4.7)
