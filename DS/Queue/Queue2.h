//
// Created by SYSTEM on 8/23/2018.
//

#ifndef ALGORITHMS_QUEUE2_H
#define ALGORITHMS_QUEUE2_H


#include <string>

class Queue2 {
public:
    Queue2();

    virtual ~Queue2();

public:
    void enqueue(std::string item);
    std::string dequeue();
    bool isEmpty();
    void resize(int capacity);

private:
    int size;
    int head;
    int tail;
    int currentLength;
    std::string * array;


};


#endif //ALGORITHMS_QUEUE2_H
