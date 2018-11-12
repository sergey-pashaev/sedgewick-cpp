cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

function(ex NUMBER) # ARGN as list of sources
  set(BIN_NAME "ex.${NUMBER}")
  add_executable("${BIN_NAME}" "${ARGN}")
  target_link_libraries("${BIN_NAME}" catch2)
endfunction()

function(ex_no_catch NUMBER) # ARGN as list of sources
  set(BIN_NAME "ex.${NUMBER}")
  add_executable("${BIN_NAME}" "${ARGN}")
endfunction()

function(program NUMBER) # ARGN as list of sources
  set(BIN_NAME "program.${NUMBER}")
  add_executable("${BIN_NAME}" "${ARGN}")
endfunction()

function(resource FILE)
  configure_file("${FILE}" "${FILE}" COPYONLY)
endfunction()

option(USE_KCOV "Use kcov if available" ON)
if(USE_KCOV)
  find_program(KCOV_PROGRAM kcov)
  set(KCOV_ARGS "--exclude-pattern=/usr/include,thirdparty")
  set(KCOV_REPORT_PATH "/tmp/kcov")
endif()

function(test_io PROGRAM CHAPTER TEST_NAME) # ARGN as list of program arguments
  file(GLOB inputs ${CMAKE_SOURCE_DIR}/test/${CHAPTER}/${TEST_NAME}.test*.in)
  foreach(input ${inputs})
    if(KCOV_PROGRAM)
      add_test(NAME "${PROGRAM}.${input}" COMMAND ${CMAKE_SOURCE_DIR}/test/coverage.sh ${CMAKE_CURRENT_BINARY_DIR}/${PROGRAM} ${input} ${ARGN})
    else()
      add_test(NAME "${PROGRAM}.${input}" COMMAND ${CMAKE_SOURCE_DIR}/test/test.sh ${CMAKE_CURRENT_BINARY_DIR}/${PROGRAM} ${input} ${ARGN})
    endif()
  endforeach(input)
endfunction()

function(test_runnable PROGRAM) # ARGN as list of args
  if(KCOV_PROGRAM)
    add_test(NAME "${PROGRAM}" COMMAND ${KCOV_PROGRAM} ${KCOV_ARGS} ${KCOV_REPORT_PATH} "${PROGRAM}" ${ARGN})
  else()
    add_test(NAME "${PROGRAM}" COMMAND "${PROGRAM}" ${ARGN})
  endif()
endfunction()

function(coveralls_upload PROGRAM) # ARGN as list of args
  if(KCOV_PROGRAM)
    if(TRAVIS_JOB_ID)
      add_test(NAME "coveralls-upload" COMMAND ${KCOV_PROGRAM} ${KCOV_ARGS} --coveralls-id=${TRAVIS_JOB_ID} ${KCOV_REPORT_PATH} "${PROGRAM}" ${ARGN})
    endif()
  endif()
endfunction()

add_subdirectory(chapter-1)
add_subdirectory(chapter-3)
add_subdirectory(chapter-4)

add_subdirectory(extra)
