cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

# program
program(1.1 program.1.1.cpp)
program(1.2 program.1.2.cpp)
program(1.3 program.1.3.cpp)
program(1.4 program.1.4.cpp)
program(connectivity connectivity.cpp)

# program tests
test(program.1.1 chapter-1 program.1.1)
test(program.1.2 chapter-1 program.1.1)
test(program.1.3 chapter-1 program.1.1)
test(program.1.4 chapter-1 program.1.1)
test_runnable(program.connectivity)

# ex
resource(ex.1.1.md)
resource(ex.1.4.md)
resource(ex.1.5.md)
resource(ex.1.6.md)
resource(ex.1.7.md)
resource(ex.1.8.md)
resource(ex.1.9.md)
resource(ex.1.10.md)
resource(ex.1.11.md)
ex(1.16 ex.1.16.cpp)
resource(ex.1.17.md)
ex(1.22 ex.1.22.cpp)
resource(ex.1.25.md)
ex(1.23 ex.1.23.cpp)
resource(ex.1.26.md)

# ex test
test(ex.1.16 chapter-1 program.1.1)
