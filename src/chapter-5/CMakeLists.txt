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
ex(NUMBER 5.6 FILES ex.5.6.cpp)
resource(ex.5.6.md)
resource(ex.5.7.md)
ex(NUMBER 5.8 FILES ex.5.8.cpp)
resource(ex.5.8.md)
ex(NUMBER 5.13 FILES ex.5.13.cpp)
ex(NUMBER 5.14 FILES ex.5.14.cpp)
ex(NUMBER 5.16 FILES ex.5.16.cpp)
ex(NUMBER 5.17 FILES ex.5.17.cpp)
ex(NUMBER 5.18 FILES ex.5.18.cpp)
ex(NUMBER 5.19 FILES ex.5.19.cpp NO_UNIT_TESTS)

# ex test
test(TARGET ex.5.1)
test(TARGET ex.5.2 TEST_SET ex.5.2)
test(TARGET ex.5.4)
test(TARGET ex.5.5)
test(TARGET ex.5.6 TEST_SET ex.5.6)
test(TARGET ex.5.8 TEST_SET ex.5.8)
test(TARGET ex.5.13)
test(TARGET ex.5.14)
test(TARGET ex.5.16)
test(TARGET ex.5.17)
test(TARGET ex.5.18)
