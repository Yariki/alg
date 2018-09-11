//
// Created by Yariki on 9/11/2018.
//

#ifndef ALGORITHMS_QUICK3WAYSORT_H
#define ALGORITHMS_QUICK3WAYSORT_H


#include "BaseSort.h"

class Quick3WaySort: public BaseSort{

public:
    Quick3WaySort();

    virtual ~Quick3WaySort();

    void Sort(int *arr, int length) override;

private:

    void sort(int * arr, int lo, int hi);

};


#endif //ALGORITHMS_QUICK3WAYSORT_H
