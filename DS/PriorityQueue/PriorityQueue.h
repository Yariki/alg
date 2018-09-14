//
// Created by Yariki on 9/14/2018.
//

#ifndef ALGORITHMS_PRIORITYQUEUE_H
#define ALGORITHMS_PRIORITYQUEUE_H


class PriorityQueue {

public:
    PriorityQueue(int size);

    virtual ~PriorityQueue();

    void insert(int val);
    int getMax();
    bool  isEmpty() {
        return  _n == 0;
    }
private:
    void fixUp(int * arr, int k);
    void fixDown(int * arr, int k, int N);
    void exch(int* arr, int i, int j);

private:
    int _n;
    int *_arr;
    bool _isMax;
};


#endif //ALGORITHMS_PRIORITYQUEUE_H
