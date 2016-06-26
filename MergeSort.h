//
// Created by yariki on 6/25/2016.
//

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H


#include "BaseSort.h"

class MergeSort : public BaseSort {

public:

    MergeSort() { }
    virtual ~MergeSort() { }

    virtual void Sort(int *arr, int length) override;

private:
    void Merge_Sort(int *arr, int start, int end);

    void Merge(int *arr, int start, int middle, int end);
};


#endif //ALGORITHMS_MERGESORT_H
