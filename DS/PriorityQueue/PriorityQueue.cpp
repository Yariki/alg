//
// Created by Yariki on 9/14/2018.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size, bool isMax):_isMax(isMax), _n(0) {
    _arr.resize(size + 1);
}

PriorityQueue::~PriorityQueue() {
}

void PriorityQueue::insert(int val) {
    _arr[++_n] = val;
    fixUp(_n);
}

int PriorityQueue::getTop() {
    auto top = _arr[1];
    exch( 1, _n--);
    fixDown( 1, _n);
    return top;
}

void PriorityQueue::fixUp(int k) {
 while(k > 1 && _isMax ? _arr[k / 2] < _arr[k] :  _arr[k / 2] > _arr[k] ){
     exch(k, k/2);
     k = k/2;
 }
}

void PriorityQueue::fixDown(int k, int N) {
    while (2 * k <= N){
            auto j = 2* k;
            if(j < N && _isMax && _arr[j] < _arr[j+1]) {
                j++;
            }else if(j < N && !_isMax && _arr[j] > _arr[j+1]){
                j++;
            }
            if(!( _isMax ? _arr[k] < _arr[j] : _arr[k] > _arr[j])) break;
            exch(k,j);
            k = j;
    }
}

void PriorityQueue::exch( int i, int j) {
    auto temp = _arr[j];
    _arr[j] = _arr[i];
    _arr[i] = temp;
}

