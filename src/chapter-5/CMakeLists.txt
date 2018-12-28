cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

# program
program(NUMBER 5.2 FILES program.5.2.cpp)

# program test

# ex
ex(NUMBER 5.1 FILES ex.5.1.cpp)
ex(NUMBER 5.2 FILES ex.5.2.cpp)
resource(ex.5.2.md)
resource(ex.5.3.md)
ex(NUMBER 5.4 FILES ex.5.4.cpp)
resource(ex.5.4.md)
ex(NUMBER 5.5 FILES ex.5.5.cpp)

# ex test
test(TARGET ex.5.1)
test(TARGET ex.5.2 TEST_SET ex.5.2)
test(TARGET ex.5.4)
test(TARGET ex.5.5)
