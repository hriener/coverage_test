cmake_minimum_required(VERSION 3.2)
project(Coverage)

message("CMAKE_COMPILER_IS_GNUCC=${CMAKE_COMPILER_IS_GNUCC}")

if (CMAKE_COMPILER_IS_GNUCC)
  option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)

  if (ENABLE_COVERAGE)
    add_compile_options(-O0 -g -fprofile-arcs -ftest-coverage)
  endif()
endif()

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(coverage coverage.cpp)
if (ENABLE_COVERAGE)
  target_link_libraries(coverage gcov)
endif()
