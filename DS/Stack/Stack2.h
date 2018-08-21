//
// Created by SYSTEM on 8/22/2018.
//

#ifndef ALGORITHMS_STACK2_H
#define ALGORITHMS_STACK2_H

#include <string>
#include <vector>

class Stack2 {

public:
    Stack2();

    virtual ~Stack2();
public:
    void push(std::string item);
    const std::string pop();
    bool isEmpty();
    void clear();

private:
    void resize(int newSize);


private:
    int lenght;
    std::string * array;
    int key;
};


#endif //ALGORITHMS_STACK2_H
