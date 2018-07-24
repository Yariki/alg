//
// Created by Yariki on 7/25/2018.
//

#ifndef ALGORITHMS_QUICKUNIONUF_H
#define ALGORITHMS_QUICKUNIONUF_H


class QuickUnionUF {

public:
    QuickUnionUF(int n);

    virtual ~QuickUnionUF();
    bool connected(int p, int q);
    void union_(int p, int q);
private:
    int findRoot(int i);

private:
    int* _array;
    int _lenght;
};


#endif //ALGORITHMS_QUICKUNIONUF_H
