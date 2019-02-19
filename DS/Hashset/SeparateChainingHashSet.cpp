//
// Created by Yariki on 2/15/2019.
//

#include <cstdio>
#include <iostream>
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
    auto index = hash(ch);
    _st->at(index)->put(ch,value);
}

int SeparateChainingHashSet::get(char ch) {
    auto index = hash(ch);
    return _st->at(index)->get(ch);
}

int SeparateChainingHashSet::hash(char ch) {
    return ((int)ch &0x7fffffff) % _m;
}

void SeparateChainingHashSet::print() {
    if(_st->size() == 0){
        return;
    }

    for (int i = 0; i < _st->size(); ++i) {
        auto set = _st->at(i);
        printf_s("Index: %d",i);
        auto next = set->getNode();
        while(next != nullptr){

            std::cout << "{ Key:" << next->get_key() << ";";
            std::cout << "Value: " << next->get_value() << ";} ";
            next = next->get_next();
        }
        std::cout << std::endl;
    }
}

