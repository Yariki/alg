//
// Created by Yariki on 5/2/2020.
//

#include "RabinKarp.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory.h>
#include <math.h>

RabinKarp::~RabinKarp() {

}

RabinKarp::RabinKarp(string filename) {
    readFile(filename);
    rm = 1;
    for (int i = 1; i <= M - 1; ++i) {
        rm = (R * rm) % Q;
    }
    patternHash = computeHash(pattern, pattern.size());
}

int RabinKarp::search() {
    int N = text.size();
    auto textHash = computeHash(text,M);
    if(patternHash == textHash && check(text,0)) return 0;

    for (int i = M; i < N; i++) {
        textHash = (textHash + Q - rm * text.at(i - M) % Q) % Q;
        textHash = (textHash * R + text.at(i)) % Q;
        if(patternHash == textHash && check(text,i - M + 1))
            return i - M +1;
    }
    return N;
}

void RabinKarp::readFile(string filename) {
    std::ifstream file(filename);
    if(file.good() && file.is_open()){
        std::getline(file, pattern);
        M = pattern.size();
        std::getline(file, text);
        file.close();
    }
}

long RabinKarp::computeHash(string t, int m) {
    long h = 0;
    for (int i = 0; i < m; ++i) {
        h = (R * h + t.at(i)) % Q;
    }
    return h;
}

bool RabinKarp::check(string text, int shift) {
    for (int i = 0; i < M; ++i) {
        if(pattern.at(i) != text.at(shift + i)){
            return false;
        }
    }
    return true;
}
