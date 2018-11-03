cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

function(ex NUMBER) # ARGN as list of sources
  set(BIN_NAME "ex.${NUMBER}")
  add_executable("${BIN_NAME}" "${ARGN}")
endfunction()

function(program NUMBER) # ARGN as list of sources
  set(BIN_NAME "program.${NUMBER}")
  add_executable("${BIN_NAME}" "${ARGN}")
endfunction()

function(ex_testable NUMBER) # ARGN as list of sources
  set(BIN_NAME "ex.${NUMBER}")
  add_executable("${BIN_NAME}" "${ARGN}")
  target_link_libraries("${BIN_NAME}" catch2)
  add_test(NAME "${BIN_NAME}" COMMAND "${BIN_NAME}")
endfunction()

function(resource FILE)
  configure_file("${FILE}" "${FILE}" COPYONLY)
endfunction()

option(USE_KCOV "Use kcov if available" ON)
if(USE_KCOV)
  find_program(KCOV_PROGRAM kcov)
endif()

function(test PROGRAM CHAPTER TEST_NAME)
  file(GLOB inputs ${CMAKE_SOURCE_DIR}/test/${CHAPTER}/${TEST_NAME}.test*.in)
  foreach(input ${inputs})
    if(KCOV_PROGRAM)
      add_test(NAME "${PROGRAM}.${input}" COMMAND ${CMAKE_SOURCE_DIR}/test/coverage.sh ${CMAKE_CURRENT_BINARY_DIR}/${PROGRAM} ${input})
    else()
      add_test(NAME "${PROGRAM}.${input}" COMMAND ${CMAKE_SOURCE_DIR}/test/test.sh ${CMAKE_CURRENT_BINARY_DIR}/${PROGRAM} ${input})
    endif()
  endforeach(input)
endfunction()

function(test_runnable PROGRAM)
  add_test(NAME "${PROGRAM}" COMMAND "${PROGRAM}")
endfunction()

add_subdirectory(chapter-1)
add_subdirectory(chapter-3)
