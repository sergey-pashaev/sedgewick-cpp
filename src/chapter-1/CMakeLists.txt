cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

program(1.1 program.1.1.cpp)
program(1.2 program.1.2.cpp)
program(1.3 program.1.3.cpp)
program(1.4 program.1.4.cpp)

resource(ex.1.4.md)
resource(ex.1.5.md)
resource(ex.1.6.md)
resource(ex.1.7.md)
resource(ex.1.8.md)
resource(ex.1.9.md)
