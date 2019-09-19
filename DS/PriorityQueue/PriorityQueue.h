//
// Created by Yariki on 9/14/2018.
//

#ifndef ALGORITHMS_PRIORITYQUEUE_H
#define ALGORITHMS_PRIORITYQUEUE_H

#include <vector>

using namespace std;

class PriorityQueue {

public:
    PriorityQueue(int size, bool isMax);

    virtual ~PriorityQueue();

    void insert(int val);
    int getTop();
    bool  isEmpty() {
        return  _n == 0;
    }
private:
    void fixUp(int k);
    void fixDown(int k, int N);
    void exch(int i, int j);

private:
    int _n;
    vector<int> _arr;
    bool _isMax;
};


#endif //ALGORITHMS_PRIORITYQUEUE_H
