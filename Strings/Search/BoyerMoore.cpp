//
// Created by Yariki on 5/2/2020.
//

#include "BoyerMoore.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <memory.h>
#include <math.h>

BoyerMoore::BoyerMoore(string filename) {
    readFile(filename);
    constructSkipTable();
}

BoyerMoore::~BoyerMoore() {

}

int BoyerMoore::search() {
    int N = text.size();
    int M = pattern.size();
    int skip = 0;
    for (int i = 0; i < N - M; i += skip) {
        skip = 0;
        for (int j = M - 1; j >=0 ; j--) {
            if(text.at(i+j) != pattern.at(j)){
                skip = std::max(1, j - skipTable[text.at(i + j)]);
                break;
            }
        }
        if(skip == 0) return i;
    }
    return N;
}

void BoyerMoore::readFile(string filename) {
    std::ifstream file(filename);
    if(file.good() && file.is_open()){
        std::getline(file, pattern);
        std::getline(file, text);
        file.close();
    }
}

void BoyerMoore::constructSkipTable() {
    if(pattern.empty()){
        throw "pattern is empty";
    }
    memset(&skipTable,-1, R * sizeof(int));
    for (int i = 0; i < pattern.size(); ++i) {
        skipTable[pattern.at(i)] = i;
    }
}
