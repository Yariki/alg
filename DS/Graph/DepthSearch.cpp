//
// Created by Yariki on 3/8/2019.
//

#include "DepthSearch.h"

DepthSearch::DepthSearch(Graph* g) {
    init(g);

    for (int j = 0; j < g->getV(); ++j) {
        if(!_marked->at(j)){
            dfs(g,j);
        }
    }
}

DepthSearch::DepthSearch(Graph* g, int s) {
    init(g);

    dfs(g,s);
}

DepthSearch::~DepthSearch() {
    delete _marked;
    delete _edgeTo;
}

void DepthSearch::init(Graph *graph) {
    _marked = new map<int,bool>();
    _edgeTo = new map<int,int>();

    for (int i = 0; i < graph->getV(); ++i) {
        _marked->insert(pair<int,bool>(i,false));
        _edgeTo->insert(pair<int,int>(i,-1));
    }
}

void DepthSearch::dfs(Graph *g, int v) {
    _marked->at(v) = true;
    auto edges = g->adj(v);

    for (auto i = edges->begin(); i != edges->end(); ++i) {
        if(!_marked->at(*i)){
            dfs(g,*i);
            _edgeTo->at(*i) = v;
        }
    }
}
