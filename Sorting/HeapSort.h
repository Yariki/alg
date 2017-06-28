//
// Created by Yariki on 5/24/2017.
//

#ifndef ALGORITHMS_HEAPSORT_H
#define ALGORITHMS_HEAPSORT_H


#include "BaseSort.h"

class HeapSort : public BaseSort {
public:
    void Sort(int *arr, int length) override;

private:
    int getParent(int currentIndex);
    int getLeft(int currentIndex);
    int getRight(int currentIndex);
    void maxHeapify(int* arr, int currentIndex, int heapSize);
    void buildMaxHeap(int * arr, int lenght, int heapSize);

};


#endif //ALGORITHMS_HEAPSORT_H
