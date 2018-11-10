cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

# program
program(4.5 program.4.5.cpp)
program(4.6 program.4.6.cpp)

# program test
test_io(program.4.5 chapter-4 "10 2 +")
test_io(program.4.6 chapter-4 "(10 + 2)")

# ex
ex(4.1 ex.4.1.cpp)
ex(4.2 ex.4.2.cpp)
ex(4.3 ex.4.3.cpp)
ex(4.4 ex.4.4.cpp)
ex(4.6 ex.4.6.cpp)
ex(4.7 ex.4.7.cpp)
resource(ex.4.9.md)
resource(ex.4.10.md)
resource(ex.4.12.md)
resource(ex.4.13.md)
ex(4.14 ex.4.14.cpp)
ex(4.15 ex.4.15.cpp)
resource(ex.4.16.md)
resource(ex.4.16.ps)

# ex test
test_runnable(ex.4.1 10 0.5)
test_runnable(ex.4.2)
test_runnable(ex.4.3)
test_runnable(ex.4.4 100)
test_runnable(ex.4.6)
test_runnable(ex.4.7)
test_runnable(ex.4.14)
test_runnable(ex.4.15)
