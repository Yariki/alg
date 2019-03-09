//
// Created by Yariki on 3/9/2019.
//

#ifndef ALGORITHMS_BREADTHSEARCH_H
#define ALGORITHMS_BREADTHSEARCH_H


#include "Graph.h"

class BreadthSearch {

public:
    BreadthSearch(Graph* g, int s);
    virtual ~BreadthSearch();

private:
    void init(Graph * g);
    void bfs(Graph* g, int s);

private:
    map<int,bool> *_marked;
    map<int,int> *_edgeTo;
    map<int,int> *_dist;


};


#endif //ALGORITHMS_BREADTHSEARCH_H
