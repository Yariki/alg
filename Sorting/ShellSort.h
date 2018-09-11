//
// Created by Yariki on 9/2/2018.
//

#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H


#include "BaseSort.h"

class ShellSort : public BaseSort {

public:
    ShellSort();
    virtual ~ShellSort();

public:
    void Sort(int *arr, int length) override;

private:
    void printArray(int* a, int length);
};


#endif //ALGORITHMS_SHELLSORT_H
