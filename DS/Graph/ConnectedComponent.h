//
// Created by Yariki on 3/16/2019.
//

#ifndef ALGORITHMS_CONNECTEDCOMPONENT_H
#define ALGORITHMS_CONNECTEDCOMPONENT_H


#include "Graph.h"

class ConnectedComponent {

public:
    ConnectedComponent(Graph *g);
    virtual ~ConnectedComponent();

public:
    bool connected(int v, int w);
    int count();
    int id(int v);
private:
    void init(Graph *g);
    void dfs(Graph *g, int v);

private:
    int _count;
    map<int,bool> *_marked;
    map<int,int> *_cc;
};


#endif //ALGORITHMS_CONNECTEDCOMPONENT_H
