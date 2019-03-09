//
// Created by Yariki on 3/9/2019.
//

#include "BreadthSearch.h"
#include <queue>

BreadthSearch::BreadthSearch(Graph *g, int s) {
    init(g);
    bfs(g,s);
}

BreadthSearch::~BreadthSearch() {
    delete _marked;
    delete _edgeTo;
    delete _dist;
}

void BreadthSearch::init(Graph *g) {
    _marked = new map<int,bool>();
    _edgeTo = new map<int,int>();
    _dist = new map<int,int>();

    for (int i = 0; i < g->getV(); ++i) {
        _marked->insert({i,false});
        _edgeTo->insert({i,-1});
        _dist->insert({i,0});
    }
}

void BreadthSearch::bfs(Graph *g, int s) {

    queue<int> q;
    q.push(s);
    _marked->at(s) = true;
    _dist->at(s) = 0;
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        auto edges = g->adj(current);
        auto  d = _dist->at(current) + 1;
        for (auto it = edges->begin(); it != edges->end() ; ++it) {
            auto ver = *it;
            if(!_marked->at(ver)){
                q.push(ver);
                _edgeTo->at(ver) = current;
                _marked->at(ver) = true;
                _dist->at(ver) = d;
            }
        }
    }
}
