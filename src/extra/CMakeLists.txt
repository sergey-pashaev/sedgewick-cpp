cmake_minimum_required(VERSION 3.1)

program(NUMBER dummy FILES dummy.cpp)
coveralls_upload(program.dummy) # program doesn't matter
