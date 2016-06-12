//
// Created by yariki on 6/12/2016.
//

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H


#include "BaseSort.h"

class InsertionSort : public BaseSort {

public:

    InsertionSort() { }

    virtual ~InsertionSort() { }

    virtual void Sort(int *arr, int length) override;


};


#endif //ALGORITHMS_INSERTIONSORT_H
