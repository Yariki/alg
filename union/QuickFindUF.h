//
// Created by Yariki on 7/25/2018.
//

#ifndef ALGORITHMS_QUICKFINDUF_H
#define ALGORITHMS_QUICKFINDUF_H


class QuickFindUF {

public:
    QuickFindUF(int n);
    virtual ~QuickFindUF();
    bool conected(int p, int q);
    void union_ (int p, int q);

private:
    int* _array;
    int _lenght;
};


#endif //ALGORITHMS_QUICKFINDUF_H
