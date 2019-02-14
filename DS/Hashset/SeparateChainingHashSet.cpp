//
// Created by Yariki on 2/15/2019.
//

#include "SeparateChainingHashSet.h"


SeparateChainingHashSet::SeparateChainingHashSet(): SeparateChainingHashSet(997) {}

SeparateChainingHashSet::SeparateChainingHashSet(int _m) : _m(_m) {
    _st = new std::vector<SequantialSearchST*>();
    for (int i = 0; i < _m; ++i) {
        _st->push_back(new SequantialSearchST());
    }
}

SeparateChainingHashSet::~SeparateChainingHashSet() {
    auto size = _st->size();
    for (int i = 0; i < size; ++i) {
        delete _st->at(i);
    }
    _st->clear();
    _st = nullptr;
}

void SeparateChainingHashSet::put(char ch, int value) {
    _st->at(hash(ch))->put(ch,value);
}

int SeparateChainingHashSet::get(char ch) {
    return _st->at(hash(ch))->get(ch);
}

int SeparateChainingHashSet::hash(char ch) {
    return ((int)ch &0x7fffffff) % _m;
}


