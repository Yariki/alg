//
// Created by Yariki on 5/2/2020.
//

#ifndef ALGORITHMS_BOYERMOORE_H
#define ALGORITHMS_BOYERMOORE_H

#include <type_traits>
#include <string>
#include <vector>
#include <map>
#include "..\..\Shared\shared.h"

using std::map;
using std::vector;
using std::string;

class BoyerMoore {

public:
    BoyerMoore(string filename);
    virtual ~BoyerMoore();

    int search();


private:
    void readFile(string filename);
    void constructSkipTable();

private:
    int skipTable[R];
    string text;
    string pattern;
};


#endif //ALGORITHMS_BOYERMOORE_H
