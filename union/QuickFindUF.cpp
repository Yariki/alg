//
// Created by Yariki on 7/25/2018.
//

#include "QuickFindUF.h"

QuickFindUF::QuickFindUF(int n) {
    _array = new int[n];
    _lenght = n;
    for(int i = 0; i < _lenght; i++) {
        _array[i] = i;
    }
}

QuickFindUF::~QuickFindUF() {
    delete [] _array;
}

bool QuickFindUF::conected(int p, int q) {
    return _array[p] == _array[q];
}

void QuickFindUF::union_(int p, int q) {
    int idP =_array[p];
    int idQ = _array[q];
    if(idP == idQ)
        return;

    for (int i = 0; i < _lenght; ++i) {
        if(_array[i] == idP){
            _array[i] = idQ;
        }
    }
}


