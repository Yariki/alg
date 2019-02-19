//
// Created by Yariki on 2/15/2019.
//

#ifndef ALGORITHMS_SEQUANTIALSEARCHST_H
#define ALGORITHMS_SEQUANTIALSEARCHST_H

class SNode{
public:
    SNode(char _key, int _value, SNode *_next);

    virtual ~SNode();

    char get_key();
    int get_value();

    SNode *get_next() const;

    void set_next(SNode *_next);

private:
    char _key;
    int _value;
    SNode* _next;

};

class SequantialSearchST {
public:
    SequantialSearchST();
    virtual ~SequantialSearchST();
    void put(char ch, int value);
    int get(char value);
    SNode *getNode() const;

private:
    SNode* _start;

};


#endif //ALGORITHMS_SEQUANTIALSEARCHST_H
