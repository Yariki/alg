//
// Created by Yariki on 2/15/2019.
//

#include "SequantialSearchST.h"

SequantialSearchST::SequantialSearchST() {
    _start = nullptr;
}

SequantialSearchST::~SequantialSearchST() {
    delete _start;
}

void SequantialSearchST::put(char ch, int value) {
    if(_start == nullptr){
        _start = new SNode(ch,value, nullptr);
        return;
    }
    auto cur = _start;
    while(cur->get_next() != nullptr){
        cur = cur->get_next();
    }
    cur->set_next(new SNode(ch,value, nullptr));
}

int SequantialSearchST::get(char value) {
    auto cur = _start;
    while (cur->get_next() != nullptr && cur->get_key() != value){
        cur = cur->get_next();
    }
    return cur->get_value();
}

char SNode::get_key() {
    return _key;
}

int SNode::get_value() {
    return _value;
}

SNode::SNode(char _key, int _value, SNode *_next) : _key(_key), _value(_value), _next(_next) {}

SNode::~SNode() {
    delete _next;
    _next = nullptr;
}

SNode *SNode::get_next() const {
    return _next;
}

void SNode::set_next(SNode *_next) {
    SNode::_next = _next;
}

SNode *SequantialSearchST::getNode() const {
    return _start;
}

