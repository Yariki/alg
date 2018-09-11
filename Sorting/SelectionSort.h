//
// Created by Yariki on 9/2/2018.
//

#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H


#include "BaseSort.h"

class SelectionSort: public BaseSort {

public:
    SelectionSort();
    virtual ~SelectionSort();

public:
    void Sort(int *arr, int length) override;
};


#endif //ALGORITHMS_SELECTIONSORT_H
