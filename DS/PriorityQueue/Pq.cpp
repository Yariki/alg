//
// Created by Yariki on 1/20/2020.
//

#include "Pq.h"

Bucket::Bucket(double key, int value) : _key(key), _value(value) {}

Bucket::~Bucket() {

}

double Bucket::getKey() const {
    return _key;
}

int Bucket::getValue() const {
    return _value;
}



Pq::Pq(int size, bool isMax):_isMax(isMax), _n(0) {
    _arr.resize(size + 1);
    for (int i = 0; i < _arr.size(); ++i) {
        _arr[i] = nullptr;
    }
}

Pq::~Pq() {
    for (int i = 0; i < _arr.size(); ++i) {
        delete _arr[i];
    }
    _arr.clear();
}

void Pq::insert(Bucket*  val) {
    _arr[++_n] = val;
    fixUp(_n);
}

Bucket* Pq::getTop() {
    auto top = _arr[1];
    exch( 1, _n--);
    fixDown( 1, _n);
    return top;
}

void Pq::fixUp(int k) {
    while(k > 1 && (_isMax ? _arr[k / 2] != nullptr && _arr[k] != nullptr &&  _arr[k / 2]->getKey() < _arr[k]->getKey() :  _arr[k / 2] != nullptr && _arr[k] != nullptr && _arr[k / 2]->getKey() > _arr[k]->getKey() )){
        exch(k, k/2);
        k = k/2;
    }
}

void Pq::fixDown(int k, int N) {
    while (2 * k <= N){
        auto j = 2* k;
        if(j < N && _isMax && _arr[j]->getKey() < _arr[j+1]->getKey()) {
            j++;
        }else if(j < N && !_isMax && _arr[j]->getKey() > _arr[j+1]->getKey()){
            j++;
        }
        if(!( _isMax ? _arr[k]->getKey() < _arr[j]->getKey() : _arr[k]->getKey() > _arr[j]->getKey())) break;
        exch(k,j);
        k = j;
    }
}

void Pq::exch( int i, int j) {
    auto temp = _arr[j];
    _arr[j] = _arr[i];
    _arr[i] = temp;
}
