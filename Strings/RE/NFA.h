//
// Created by ADMIN on 05/05/2020.
//

#ifndef ALGORITHMS_NFA_H
#define ALGORITHMS_NFA_H

#include <string>
#include <vector>
#include <stack>
#include "..\..\DS\Graph\Direct\Digraph.h"

using std::vector;
using std::string;
using std::stack;

class NFA {
public:
    NFA(string regex);
    virtual ~NFA();

    bool isMatch(string txt);

private:
    void buildNFAGraph();

private:

    string re;
    Digraph* G;
    int M;

};


#endif //ALGORITHMS_NFA_H
