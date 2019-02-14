//
// Created by Yariki on 2/15/2019.
//

#ifndef ALGORITHMS_SEPARATECHAININGHASHSET_H
#define ALGORITHMS_SEPARATECHAININGHASHSET_H


#include <vector>
#include "SequantialSearchST.h"

class SeparateChainingHashSet {

public:
    SeparateChainingHashSet();
    virtual ~SeparateChainingHashSet();

    SeparateChainingHashSet(int _m);
    void put(char ch, int value);
    int get(char ch);

private:
    int hash(char ch);

private:
    std::vector<SequantialSearchST*> *_st;
    int _m;


};


#endif //ALGORITHMS_SEPARATECHAININGHASHSET_H
