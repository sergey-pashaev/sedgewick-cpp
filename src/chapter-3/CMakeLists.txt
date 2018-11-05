cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

# program
program(3.2 program.3.2.cpp)
program(3.5 program.3.5.cpp)

# program test
test_io(program.3.5 chapter-3 program.3.5)

# ex
ex(3.1 ex.3.1.cpp)
ex(3.2 ex.3.2.cpp)
ex(3.3 ex.3.3.cpp)
ex(3.4 ex.3.4.cpp)
ex(3.5 ex.3.5.cpp)
ex(3.6 ex.3.6.cpp)
ex(3.7 ex.3.7.cpp point.cpp)
ex(3.8 ex.3.8.cpp point.cpp)
ex(3.9 ex.3.9.cpp triangle.cpp point.cpp)
ex(3.10 ex.3.10)
ex(3.11.char ex.3.11.char.cpp)
ex(3.11.bit ex.3.11.bit.cpp)
resource(ex.3.11.sh)
ex(3.12 ex.3.12.cpp)

# ex test
test_runnable(ex.3.1)
test_runnable(ex.3.2)
test_runnable(ex.3.3)
test_runnable(ex.3.4)
test_runnable(ex.3.5)
test_runnable(ex.3.6)
test_io(ex.3.7 chapter-3 ex.3.7)
test_runnable(ex.3.8)
test_runnable(ex.3.9 10)
test_io(ex.3.10 chapter-3 ex.3.10)
test_io(ex.3.11.char chapter-3 program.3.5)
test_io(ex.3.11.bit chapter-3 program.3.5)
test_io(ex.3.12 chapter-3 ex.3.12)
