//
// Created by Yariki on 3/16/2019.
//

#include "ConnectedComponent.h"

ConnectedComponent::ConnectedComponent(Graph *g) {
    init(g);
    _count = 0;
    for (int i = 0; i < g->getV(); ++i) {
        if(!_marked->at(i)){
            dfs(g,i);
            _count++;
        }
    }
}

ConnectedComponent::~ConnectedComponent() {
    delete _marked;
    delete _cc;
}

bool ConnectedComponent::connected(int v, int w) {
    auto vc = _cc->at(v);
    auto wc = _cc->at(w);
    return vc == wc;
}

int ConnectedComponent::count() {
    return _count;
}

int ConnectedComponent::id(int v) {
    return _cc->at(v);
}

void ConnectedComponent::dfs(Graph *g, int v) {
    _marked->at(v) = true;
    _cc->at(v) = _count;

    auto edges = g->adj(v);

    for (auto i = edges->begin(); i != edges->end() ; ++i) {
        if(!_marked->at(*i)){
            dfs(g,*i);
        }
    }
}

void ConnectedComponent::init(Graph *g) {
    _marked = new map<int,bool>();
    _cc = new map<int,int>();

    for (int i = 0; i < g->getV(); ++i) {
        _marked->insert(pair<int,bool>(i,false));
        _cc->insert(pair<int,int>(i,-1));
    }
}
