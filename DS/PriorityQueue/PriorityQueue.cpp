//
// Created by Yariki on 9/14/2018.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size) {
    _arr = new int[size + 1];
    _n = 0;
    _isMax = false;

}

PriorityQueue::~PriorityQueue() {
    delete [] _arr;
}

void PriorityQueue::insert(int val) {
    _arr[++_n] = val;
    fixUp(_arr,_n);
}

int PriorityQueue::getMax() {
    exch(_arr, 1, _n);
    fixDown(_arr, 1, _n - 1);
    return _arr[_n--];
}

void PriorityQueue::fixUp(int *arr, int k) {
 while(k > 1 && _isMax ? _arr[k / 2] < _arr[k] :  _arr[k / 2] > _arr[k] ){
     exch(arr,k, k/2);
     k = k/2;
 }
}

void PriorityQueue::fixDown(int *arr, int k, int N) {
    while (2 * k <= N){
            auto j = 2* k;
            if(j < N && _isMax ? arr[j] < arr[j+1] : arr[j] > arr[j+1]) j++;
            if(!( _isMax ? arr[k] < arr[j] : arr[k] > arr[j])) break;
            exch(arr,k,j);
            k = j;
    }
}

void PriorityQueue::exch(int *arr, int i, int j) {
    auto temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

