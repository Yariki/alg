//
// Created by Yariki on 1/20/2020.
//

#ifndef ALGORITHMS_PQ_H
#define ALGORITHMS_PQ_H

#include <vector>

using namespace std;

class Bucket {

public:
    Bucket(int key, int value);

    virtual ~Bucket();

    int getKey() const;

    int getValue() const;

private:
    int _key;
    int _value;
};



class Pq {

public:
    Pq(int size, bool isMax);

    virtual ~Pq();

    void insert(Bucket* val);
    Bucket* getTop();
    bool  isEmpty() {
        return  _n == 0;
    }
private:
    void fixUp(int k);
    void fixDown(int k, int N);
    void exch(int i, int j);

private:
    int _n;
    vector<Bucket*> _arr;
    bool _isMax;


};


#endif //ALGORITHMS_PQ_H
