//
// Created by Yariki on 3/8/2019.
//

#ifndef ALGORITHMS_DEPTHSEARCH_H
#define ALGORITHMS_DEPTHSEARCH_H


#include "Graph.h"

class DepthSearch {

public:
    DepthSearch(Graph* g);
    DepthSearch(Graph* g, int s);
    DepthSearch(Graph* g, vector<int> &list);
    virtual ~DepthSearch();
    void dfs(Graph* g, int v);
    bool marked(int v);

private:
    void init(Graph* graph);

private:
    map<int,bool> *_marked;
    map<int,int> *_edgeTo;

};


#endif //ALGORITHMS_DEPTHSEARCH_H
