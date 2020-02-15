//
// Created by Yariki on 2/15/2020.
//

#include <fstream>
#include <iostream>
#include <memory.h>

#include "LSD.h"

LSD::LSD(string filename) {
    init(filename);
}

LSD::~LSD() {

}

void LSD::init(string filename) {
    std::ifstream file(filename);
    if(file.good() && file.is_open()){
        string line;
        std::getline(file, line);
        strings.push_back(line);

        while(!file.eof()){
            std::getline(file,line);
            strings.push_back(line);
        }

        file.close();
    }
}

vector<string> LSD::sort() {
    int N = strings.size();
    int R = 256;
    vector<string> aux(N);
    int W = strings[0].size();

    for(int d = W - 1; d >= 0; d--){
        int count[R+1];
        memset(count,0, sizeof(int) * (R + 1));
        for(int i = 0; i < N; i++){
            count[strings[i].at(d) + 1]++;
        }
        for (int i = 0; i < R; ++i) {
            count[i + 1] += count[i];
        }
        for (int i = 0; i < N; ++i) {
            aux[count[strings[i].at(d)]++] = strings[i];
        }
        for (int i = 0; i < N; ++i) {
            strings[i] = aux[i];
        }
    }
    return strings;
}
