//
// Created by Yariki on 6/28/2017.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H


#include "BaseSort.h"

class QuickSort : public BaseSort{
public:
    QuickSort(){}
    virtual ~QuickSort(){}
    void Sort(int *arr, int length) override;

private:
    void QuickSorting(int* arr, int low, int hight);

};


#endif //ALGORITHMS_QUICKSORT_H
