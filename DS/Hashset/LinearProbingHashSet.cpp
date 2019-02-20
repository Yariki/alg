//
// Created by Yariki on 2/20/2019.
//

#include "LinearProbingHashSet.h"

LinearProbingHashSet::LinearProbingHashSet() {
    M = 30;
    for (int i = 0; i < M; ++i) {
        _bucket->push_back(nullptr);
    }
    n = 0;
}

LinearProbingHashSet::LinearProbingHashSet(int cap) {
    M = cap;
    for (int i = 0; i < cap; ++i) {
        _bucket->push_back(nullptr);
    }
    n = 0;
}

LinearProbingHashSet::~LinearProbingHashSet() {

}

LPNode::LPNode(char _key, int _value, bool _isDeleted) : _key(_key), _value(_value), _isDeleted(_isDeleted) {}

LPNode::~LPNode() {

}

char LPNode::get_key() const {
    return _key;
}

void LPNode::set_key(char _key) {
    LPNode::_key = _key;
}

int LPNode::get_value() const {
    return _value;
}

void LPNode::set_value(int _value) {
    LPNode::_value = _value;
}

bool LPNode::is_isDeleted() const {
    return _isDeleted;
}

void LPNode::set_isDeleted(bool _isDeleted) {
    LPNode::_isDeleted = _isDeleted;
}

int LinearProbingHashSet::hash(char ch) {
    return ((int)ch &0x7fffffff) % M;
}

void LinearProbingHashSet::resize(int cap) {
    auto hs = new LinearProbingHashSet(cap);
    for (int i = 0; i < M; ++i) {
        if(_bucket->at(i) != nullptr){
            auto node = _bucket->at(i);
            hs->put(node->get_key(),node->get_value());
        }
    }
    deleteBuckets(_bucket);
    this->_bucket = hs->_bucket;
    this->M = hs->M;
}

void LinearProbingHashSet::deleteBuckets(std::vector<LPNode *> *bucket) {
    for (int i = 0; i < bucket->size(); ++i) {
        delete bucket->at(i);
    }
    bucket->clear();
}

void LinearProbingHashSet::put(char key, int value) {

    if(n >= M / 2){
        resize(2 * M);
    }
    int i = 0;
    for( i = hash(key); _bucket->at(i) != nullptr; i = (i + 1) % M){
        LPNode* node = _bucket->at(i);
        if(node->get_key() == key){
            node->set_value(value);
            return;
        }
    }
    _bucket->at(i) = new LPNode(key, value, false);
    n++;
}

int LinearProbingHashSet::get(char key) {
    for (int i = hash(key); _bucket->at(i) != nullptr ; i = (i + 1) % M) {
        LPNode *node = _bucket->at(i);
        if(node->get_key() == key){
            return node->get_value();
        }
    }
    return -1;
}
