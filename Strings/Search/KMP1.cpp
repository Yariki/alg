
#include "KMP1.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <memory.h>


KmpSearch::KmpSearch(string filename) {
    readFile(filename);
}


KmpSearch::~KmpSearch() {
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

int KmpSearch::search() {

    if(pattern.empty()){
        throw "pattern in empty";
    }
    const int M = pattern.size();
    int dfa[R][M];
    
    memset(&dfa,0,R * M * sizeof(int));
    
    dfa[pattern.at(0)][0] = 1;
    int X, j;
    for (X = 0, j = 1;  j < M; j++) {
        for (int c= 0; c < R; ++c) {
            dfa[c][j] = dfa[c][X];
        }
        int ch = pattern.at(j);
        printf("%d\n", ch);
        dfa[ch][j] = j + 1;
        X = dfa[ch][X];
    }

    int i, N = text.size();

    for (i = 0, j = 0; i < N && j < M ; i++) {
        j = dfa[text.at(i)][j];
    }
    return j == M ? i - M : N;
}



