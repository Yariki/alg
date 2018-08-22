//
// Created by SYSTEM on 8/23/2018.
//

#ifndef ALGORITHMS_QUEUE1_H
#define ALGORITHMS_QUEUE1_H

#include <string>

class QNode{

public:
    QNode(){
        next = nullptr;
    }

public:
    std::string item;
    QNode * next;
};

class Queue1 {

public:
    Queue1();

    virtual ~Queue1();

public:
    void enqueue(std::string item);
    std::string dequeue();
    bool isEmpty();

private:
    QNode* first;
    QNode* last;

};


#endif //ALGORITHMS_QUEUE1_H
