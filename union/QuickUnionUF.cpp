//
// Created by Yariki on 7/25/2018.
//

#include "QuickUnionUF.h"

QuickUnionUF::QuickUnionUF(int n) {
    _array = new int[n];
    _lenght = n;
    for (int i = 0; i < n; ++i) {
        _array[i] = i;
    }
}

QuickUnionUF::~QuickUnionUF() {
    delete [] _array;
}

bool QuickUnionUF::connected(int p, int q) {
    return findRoot(p) == findRoot(q);
}

void QuickUnionUF::union_(int p, int q) {
    int pId = findRoot(p);
    int qId = findRoot(q);
    _array[pId] = qId;
}

int QuickUnionUF::findRoot(int i) {
    while(i != _array[i]) i = _array[i];
    return i;
}
