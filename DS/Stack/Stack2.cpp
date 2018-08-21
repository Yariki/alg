//
// Created by SYSTEM on 8/22/2018.
//

#include "Stack2.h"

Stack2::Stack2() :lenght(1), key(0) {
    array = new std::string[lenght];
}

Stack2::~Stack2() {
    delete[] array;
}

void Stack2::push(std::string item) {

    if(key == lenght){
        lenght *= 2;
        resize(lenght);
    }
    array[key++] = item;
}

const std::string Stack2::pop() {
    auto item = array[--key];
    array[key] = nullptr;
    if(key > 0 && key == (lenght / 4)){
        lenght /=2;
        resize(lenght);
    }
    return item;
}

bool Stack2::isEmpty() {
    return lenght == 0;
}

void Stack2::clear() {
    delete[] array;
    lenght = 1;
    key = 0;
    array = new std::string[lenght];
}

void Stack2::resize(int newSize) {

    auto newArray = new std::string[newSize];
    for (int i = 0; i < key; ++i) {
        newArray[i] = array[i];
    }
    array = newArray;
}



