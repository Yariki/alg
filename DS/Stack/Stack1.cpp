//
// Created by SYSTEM on 8/21/2018.
//

#include "Stack1.h"


Stack1::Stack1() {
    head = nullptr;
}

Stack1::~Stack1() {

    while(head != nullptr){
        auto temp = head;
        head = head->next;
        delete temp;
    }
}

void Stack1::push(std::string item) {
    if(head == nullptr){
        head = new Node();
        head->item = item;
        head->item = nullptr;
    } else {
        auto newNode = new Node();
        newNode->item = item;
        newNode->next = head;
        head = newNode;
    }
}

const Node *Stack1::pop(){
    auto temp = head;
    head = head->next;
    return temp;
}

bool Stack1::isEmpty() {
    return false;
}

void Stack1::clear() {

}

Node::Node()  {
    next = nullptr;
}
