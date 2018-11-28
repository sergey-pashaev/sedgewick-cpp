cmake_minimum_required(VERSION 3.1..3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_VERSION})
endif()

function(ex)
  set(options NO_UNIT_TESTS)
  set(args NUMBER)
  set(lists FILES)
  cmake_parse_arguments(EX "${options}" "${args}" "${lists}" ${ARGN})
  set(name "ex.${EX_NUMBER}")
  add_executable("${name}" "${EX_FILES}")
  if(NOT EX_NO_UNIT_TESTS)
    target_link_libraries("${name}" catch2)
  endif()
endfunction()

function(program)
  set(args NUMBER)
  set(lists FILES)
  cmake_parse_arguments(PROGRAM "" "${args}" "${lists}" ${ARGN})
  set(name "program.${PROGRAM_NUMBER}")
  add_executable("${name}" "${PROGRAM_FILES}")
endfunction()

function(resource FILE)
  configure_file("${FILE}" "${FILE}" COPYONLY)
endfunction()

option(USE_KCOV "Use kcov if available" ON)
if(USE_KCOV)
  find_program(KCOV_PROGRAM kcov)
  set(KCOV_ARGS "--exclude-pattern=/usr/include,thirdparty,/usr/lib")
  set(KCOV_REPORT_PATH "/tmp/kcov")
endif()

function(test)
  set(args TARGET TEST_SET)
  set(lists CLI_ARGS)
  cmake_parse_arguments(TEST "" "${args}" "${lists}" ${ARGN})
  if (TEST_TEST_SET)
    # IO TEST SET TEST
    # split test_set arg to get chapter number
    # <type>.<chapter>.<number>
    string(REPLACE "." ";" parts "${TEST_TEST_SET}")
    list(GET parts 1 chapter)

    file(GLOB inputs ${CMAKE_SOURCE_DIR}/test/chapter-${chapter}/${TEST_TEST_SET}.test*.in)
    foreach(input ${inputs})
      # make nice test name
      string(REPLACE "${CMAKE_SOURCE_DIR}/test/chapter-${chapter}/" "" test_name "${input}")
      set(test_name "${TEST_TARGET}_on_test_set_${test_name}")
      if (TEST_CLI_ARGS)
        string(REPLACE ";" "_" str_args "${TEST_CLI_ARGS}")
        set(test_name "${test_name}_with_args_${str_args}")
      endif()

      # choose test runner
      if (USE_KCOV AND KCOV_PROGRAM)
        set(test_runner "run-test-coverage.sh")
        add_test(NAME ${test_name} COMMAND ${CMAKE_SOURCE_DIR}/scripts/${test_runner} ${CMAKE_CURRENT_BINARY_DIR}/${TEST_TARGET} ${input} ${KCOV_PROGRAM} ${KCOV_ARGS} ${KCOV_REPORT_PATH})
      else()
        set(test_runner "run-test.sh")
        add_test(NAME ${test_name} COMMAND ${CMAKE_SOURCE_DIR}/scripts/${test_runner} ${CMAKE_CURRENT_BINARY_DIR}/${TEST_TARGET} ${input})
      endif()

    endforeach()
  else()
    # UNIT TESTS
    set(test_name "${TEST_TARGET}")
    if (TEST_CLI_ARGS)
      string(REPLACE ";" "_" str_args "${TEST_CLI_ARGS}")
      set(test_name "${TEST_TARGET}_with_args_${str_args}")
    endif()
    if(USE_KCOV AND KCOV_PROGRAM)
      add_test(NAME ${test_name} COMMAND ${KCOV_PROGRAM} ${KCOV_ARGS} ${KCOV_REPORT_PATH} "${TEST_TARGET}" ${TEST_CLI_ARGS})
    else()
      add_test(NAME ${test_name} COMMAND "${TEST_TARGET}" ${TEST_CLI_ARGS})
    endif()
  endif()
endfunction()

function(coveralls_upload PROGRAM) # ARGN as list of args
  if(USE_KCOV AND KCOV_PROGRAM)
    if(TRAVIS_JOB_ID)
      add_test(NAME "coveralls-upload" COMMAND ${KCOV_PROGRAM} ${KCOV_ARGS} --coveralls-id=${TRAVIS_JOB_ID} ${KCOV_REPORT_PATH} "${PROGRAM}" ${ARGN})
    endif()
  endif()
endfunction()

add_subdirectory(chapter-1)
add_subdirectory(chapter-3)
add_subdirectory(chapter-4)

add_subdirectory(extra)
