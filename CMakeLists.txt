cmake_minimum_required(VERSION 3.5)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BaseSort.cpp BaseSort.h InsertionSort.cpp InsertionSort.h MergeSort.cpp MergeSort.h HeapSort.cpp HeapSort.h)
add_executable(algorithms ${SOURCE_FILES})