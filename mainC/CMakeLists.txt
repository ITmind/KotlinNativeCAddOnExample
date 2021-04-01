CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(TestC VERSION 0.1 LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_compile_options(/EHa)
add_executable(TestC main.cpp)
