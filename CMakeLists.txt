cmake_minimum_required(VERSION 3.5)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Sorting/BaseSort.cpp Sorting/BaseSort.h Sorting/InsertionSort.cpp Sorting/InsertionSort.h Sorting/MergeSort.cpp Sorting/MergeSort.h Sorting/HeapSort.cpp Sorting/HeapSort.h Sorting/QuickSort.cpp Sorting/QuickSort.h DS/BSTree/BSTree.cpp DS/BSTree/BSTree.h DS/BSTree/BSTNode.cpp DS/BSTree/BSTNode.h DS/RBTree/RBNode.cpp DS/RBTree/RBNode.h DS/RBTree/RBTree.cpp DS/RBTree/RBTree.h union/QuickFindUF.cpp union/QuickFindUF.h union/QuickUnionUF.cpp union/QuickUnionUF.h DS/Stack/Stack1.cpp DS/Stack/Stack1.h DS/Stack/Stack2.cpp DS/Stack/Stack2.h DS/Queue/Queue1.cpp DS/Queue/Queue1.h DS/Queue/Queue2.cpp DS/Queue/Queue2.h)
add_executable(algorithms ${SOURCE_FILES})