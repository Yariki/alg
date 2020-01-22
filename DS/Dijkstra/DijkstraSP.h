//
// Created by Yariki on 1/23/2020.
//

#ifndef ALGORITHMS_DIJKSTRASP_H
#define ALGORITHMS_DIJKSTRASP_H


#include "EdgeWeightedDigraph.h"
#include "../PriorityQueue/Pq.h"
#include <stack>

using namespace std;

class DijkstraSP {

public:
    DijkstraSP(EdgeWeightedDigraph *graph, int s);
    virtual ~DijkstraSP();
    double disTo(int v);
    bool hasPathTo(int v);
    stack<DirectedEdge*> pathTo(int v);

private:
    void relax(EdgeWeightedDigraph* graph,int v);

private:
    EdgeWeightedDigraph* graph;
    vector<double> distTo;
    vector<DirectedEdge*> edgeTo;
    Pq* pq;
};


#endif //ALGORITHMS_DIJKSTRASP_H
