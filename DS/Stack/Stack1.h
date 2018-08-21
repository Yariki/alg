//
// Created by SYSTEM on 8/21/2018.
//

#ifndef ALGORITHMS_STACK1_H
#define ALGORITHMS_STACK1_H

#include <string>

class Node {

public:

    Node();

    std::string item;
    Node* next;
};

class Stack1 {

public:
    Stack1();
	virtual ~Stack1();
public:
    void push(std::string item);
    const Node* pop();
    bool isEmpty();
    void clear();
private:
	Node* head;
};

#endif //ALGORITHMS_STACK1_H
