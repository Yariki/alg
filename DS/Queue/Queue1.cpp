//
// Created by SYSTEM on 8/23/2018.
//

#include "Queue1.h"

Queue1::Queue1() {}

Queue1::~Queue1() {

    while (first != nullptr){
        auto temp = first;
        first = first->next;
        delete temp;
    }
}

void Queue1::enqueue(std::string item) {
    auto node = new QNode();
    node->item = item;
    if(first == nullptr && last == nullptr){
        first = last = node;
    } else if( last != nullptr){
        auto oldlast = last;
        oldlast->next = node;
        last = node;
    }
}

std::string Queue1::dequeue() {
    auto item = first->item;
    auto oldFirst = first;
    first = oldFirst->next;

    delete oldFirst;
    if(isEmpty()){
        last = nullptr;
    }
    return item;
}

bool Queue1::isEmpty() {
    return first == nullptr;
}
