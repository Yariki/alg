//
// Created by yariki on 6/12/2016.
//

#ifndef ALGORITHMS_BASESORT_H
#define ALGORITHMS_BASESORT_H


#include <array>

class BaseSort {

public:
    BaseSort() { }
    virtual ~BaseSort() { }
    virtual void Sort(int * arr, int length) = 0;

};


#endif //ALGORITHMS_BASESORT_H
