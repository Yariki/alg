//
// Created by Yariki on 3/27/2019.
//

#include "TopologicalSort.h"


TopologicalSort::TopologicalSort(Graph *g) {
    init(g);
    for (int i = 0; i < g->getV(); ++i) {
        if(!_marked->at(i)){
            dfs(g,i);
        }
    }
}

TopologicalSort::~TopologicalSort() {
    delete _marked;
    delete _reverseOrder;
}

stack<int> *TopologicalSort::order() const {
    return _reverseOrder;
}

void TopologicalSort::init(Graph *g) {
    _marked = new map<int,bool>();
    _reverseOrder = new stack<int>();
    for (int i = 0; i < g->getV(); ++i) {
        _marked->insert(pair<int,bool>(i,false));
    }
}

void TopologicalSort::dfs(Graph *g, int v) {
    _marked->at(v) = true;
    auto edges = g->adj(v);

    for (auto i = edges->begin(); i != edges->end(); ++i) {
        if(!_marked->at(*i)){
            dfs(g,*i);
        }
    }
    _reverseOrder->push(v);
}
