//
// Created by Yariki on 3/27/2019.
//

#ifndef ALGORITHMS_TOPOLOGICALSORT_H
#define ALGORITHMS_TOPOLOGICALSORT_H


#include "Graph.h"
#include <stack>

class TopologicalSort {

public:
    TopologicalSort(Graph *h);
    virtual ~TopologicalSort();

public:
    stack<int>* order() const;

private:
    void init(Graph *g);
    void dfs(Graph *g,  int v);

private:
    map<int,bool> *_marked;
    stack<int> *_reverseOrder;

};


#endif //ALGORITHMS_TOPOLOGICALSORT_H
