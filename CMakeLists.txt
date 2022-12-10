cmake_minimum_required(VERSION 3.0)
project(CEAddress VERSION 0.1.0)

option(BUILD_EXAMPLE "build example" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(CEAddress)

if(BUILD_EXAMPLE)
  add_subdirectory(example)
endif(BUILD_EXAMPLE)

