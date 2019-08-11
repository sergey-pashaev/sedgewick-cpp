cmake_minimum_required(VERSION 3.1)

# program
program(NUMBER 1.1 FILES program.1.1.cpp)
program(NUMBER 1.2 FILES program.1.2.cpp)
program(NUMBER 1.3 FILES program.1.3.cpp)
program(NUMBER 1.4 FILES program.1.4.cpp)
program(NUMBER connectivity FILES connectivity.cpp)

# program tests
test(TARGET program.1.1 TEST_SET program.1.1)
test(TARGET program.1.2 TEST_SET program.1.1)
test(TARGET program.1.3 TEST_SET program.1.1)
test(TARGET program.1.4 TEST_SET program.1.1)
test(TARGET program.connectivity)

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
ex(NUMBER 1.16 FILES ex.1.16.cpp)
resource(ex.1.17.md)
ex(NUMBER 1.22 FILES ex.1.22.cpp)
resource(ex.1.25.md)
ex(NUMBER 1.23 FILES ex.1.23.cpp)
resource(ex.1.23.md)
resource(ex.1.26.md)

# ex test
test(TARGET ex.1.16 TEST_SET program.1.1)
