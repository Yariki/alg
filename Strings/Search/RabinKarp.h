//
// Created by Yariki on 5/2/2020.
//

#ifndef ALGORITHMS_RABINKARP_H
#define ALGORITHMS_RABINKARP_H

#include <type_traits>
#include <string>
#include <vector>
#include <map>
#include "..\..\Shared\shared.h"

using std::map;
using std::vector;
using std::string;

class RabinKarp {

public:
    RabinKarp(string filename);
    virtual ~RabinKarp();
    int search();

private:
    void readFile(string filename);
    long computeHash(string t, int m);
    bool check(string text, int shift);

private:
    string pattern;
    string text;
    long patternHash;
    long rm;
    int M;
};


#endif //ALGORITHMS_RABINKARP_H
