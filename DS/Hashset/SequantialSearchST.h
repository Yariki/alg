//
// Created by Yariki on 2/15/2019.
//

#ifndef ALGORITHMS_SEQUANTIALSEARCHST_H
#define ALGORITHMS_SEQUANTIALSEARCHST_H

class Node{
public:
    Node(char _key, int _value, Node *_next);

    virtual ~Node();

    char get_key() const;
    int get_value() const;

    Node *get_next() const;

    void set_next(Node *_next);

private:
    char _key;
    int _value;
    Node* _next;

};

class SequantialSearchST {
public:
    SequantialSearchST();
    virtual ~SequantialSearchST();
    void put(char ch, int value);
    int get(char value);

private:
    Node* _start;

};


#endif //ALGORITHMS_SEQUANTIALSEARCHST_H
