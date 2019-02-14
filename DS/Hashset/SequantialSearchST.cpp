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
        _start = new Node(ch,value, nullptr);
        return;
    }
    auto cur = _start;
    while(cur->get_next() != nullptr){
        cur = cur->get_next();
    }
    cur->set_next(new Node(ch,value, nullptr));
}

int SequantialSearchST::get(char value) {
    auto cur = _start;
    while (cur->get_next() != nullptr && cur->get_key() != value){
        cur = cur->get_next();
    }
    return cur->get_value();
}

char Node::get_key() const {
    return _key;
}

int Node::get_value() const {
    return _value;
}

Node::Node(char _key, int _value, Node *_next) : _key(_key), _value(_value), _next(_next) {}

Node::~Node() {
    delete _next;
    _next = nullptr;
}

Node *Node::get_next() const {
    return _next;
}

void Node::set_next(Node *_next) {
    Node::_next = _next;
}

