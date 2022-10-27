# ======================================================================= #
project(unit_test_playground)

cmake_minimum_required(VERSION 3.0)

# Check own repository URL
execute_process (
  OUTPUT_VARIABLE var
  COMMAND bash -c "git -C ${CMAKE_SOURCE_DIR} config --get remote.origin.url"
)
# Set own URL to distinguish between external repos and this repo
set(DEP_REPO_URL ${var})

# ================================ GTEST ==================================== #
# Download and unpack googletest at configure
if (NOT HAS_GTEST)
  message("  ------------------ ----------------- ------------------")
  message("  ------------------ Configuring GTEST ------------------")
  message("  ------------------ ----------------- ------------------")

  # Check if the repository has been downloaded already
  execute_process (
    RESULT_VARIABLE result
    OUTPUT_VARIABLE var
    # Check URL of downloaded repository
    COMMAND bash -c "git -C ${CMAKE_SOURCE_DIR}/googletest config --get \
            remote.origin.url"
  )
  # Above command returns the URL of "dependencies" if folder exists but does
  # not contain a valid repository itself
  if (result OR ("${var}" STREQUAL ${DEP_REPO_URL}))
    set(DOWNLOAD_GTEST 1)
  endif()

  configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/CMakeLists.txt.gtest
    ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt
  )

  execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" ${TOOLCHAIN_FILE_OPTION} .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
  )
  if (result)
    message(FATAL_ERROR "CMake step for gtest failed: ${result}")
  endif()

  execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
  )
  if (result)
    message(FATAL_ERROR "Build step for gtest failed: ${result}")
  endif()

  set(HAS_GTEST ON CACHE BOOL "Have we downloaded gtest?")
endif ()

# ======================================================================= #

find_package(GTest REQUIRED
             HINTS ${CMAKE_BINARY_DIR}/lib/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(
  include
  unit_tests
  ${CMAKE_BINARY_DIR}/include
  ${GTEST_INCLUDE_DIRS}
)

link_directories(${CMAKE_BINARY_DIR}/lib)

# Add test source files here
set(test_sources
  ${CMAKE_SOURCE_DIR}/unit_tests/test_runner.cpp
  ${CMAKE_SOURCE_DIR}/unit_tests/test_template.cpp
)

# Add test source files for production code here
set(sources
#  ${CMAKE_SOURCE_DIR}/src/some_file.cpp
)

add_executable(test_runner ${sources} ${test_sources})

target_link_libraries(test_runner
    gtest
    gmock
    pthread
)

