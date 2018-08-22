//
// Created by SYSTEM on 8/23/2018.
//

#include "Queue2.h"

Queue2::Queue2() {

    head = 0;
    tail = 0;
    size = 0;
    array = new std::string[4];
    currentLength = 4;
}

Queue2::~Queue2() {
    delete[] array;
}

void Queue2::enqueue(std::string item) {

    if(size == currentLength){
        resize(currentLength * 2);
    }
    size++;
    array[tail] = item;
    tail = (tail + 1) % currentLength;
}

std::string Queue2::dequeue() {
    auto item = array[head];
    head = (head + 1) % currentLength;
    size--;
    return item;
}

void Queue2::resize(int capacity) {
    auto newArray = new std::string[capacity];
    int index= 0;

    for (int i = head; i <= tail; ++i) {
        newArray[index++] = array[i];
    }

    currentLength = capacity;
    array = newArray;
    head = 0;
    tail = (index - 1) % currentLength;
}

bool Queue2::isEmpty() {
    return currentLength == 0;
}
