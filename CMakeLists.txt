cmake_minimum_required(VERSION 3.16)
project(algst)

set(CMAKE_BUILD_TYPE Debug)

file(GLOB ALGST_SRCS ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
     ${CMAKE_CURRENT_LIST_DIR}/util/*.cpp)

add_library(algst SHARED ${ALGST_SRCS})
target_include_directories(
  algst
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
  PRIVATE ${CMAKE_CURRENT_LIST_DIR}/util)

file(GLOB ALGST_TEST_SRCS ${CMAKE_CURRENT_LIST_DIR}/test/*.cpp)
add_executable(algst_test ${ALGST_TEST_SRCS})
target_include_directories(algst_test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(algst_test algst gtest gtest_main pthread)
