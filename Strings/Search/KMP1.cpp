
#include "KMP1.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <memory.h>


const int R = 256;

KmpSearch::KmpSearch(string filename) {
    readFile(filename);
    fillDfa();
}


KmpSearch::~KmpSearch() {
    for (int i = 0; i < R; ++i) {
        delete[] dfa[i];
    }
    delete[] *dfa;
}

void KmpSearch::readFile(string filename) {
    std::ifstream file(filename);
    if(file.good() && file.is_open()){
        string temp;
        std::getline(file, temp);
        pattern = temp;
        std::getline(file, temp);
        text = temp;
    }
}

void KmpSearch::fillDfa() {
    if(pattern.empty()){
        throw "pattern in empty";
    }
    auto M = pattern.size();
    dfa = new int*[R];
    for (int i = 0; i < R; ++i) {
        dfa[i] = new int[M];
    }
    memset(dfa,0, R * M * sizeof(int));
    dfa[0][0] = 1;
    int X, j;
    for (X = 0, j = 1;  j < M; j++) {
        for (int c= 0; c < R; ++c) {
            dfa[c][j] = dfa[c][X];
        }
        dfa[pattern.at(j)][j] = j + 1;
        X = dfa[pattern.at(j)][X];
    }
}

int KmpSearch::search() {
    int i, j, N = text.size(), M = pattern.size();

    for (i = 0, j = 0; i < N && j < M ; i++) {
        j = dfa[text.at(i)][j];
    }
    return j == M ? i - M : N;
}



