//
// Created by Yariki on 9/15/2019.
//

#ifndef ALGORITHMS_EDGEWEIGHTEDGRAPH_H
#define ALGORITHMS_EDGEWEIGHTEDGRAPH_H


using namespace std;

#include <string>
#include <vector>
#include <map>
#include "Edge.h"

class EdgeWeightedGraph {

public:
    EdgeWeightedGraph(int v);
    virtual ~EdgeWeightedGraph();

public:
    void  addEdge(Edge* e);
    vector<Edge*>* edges(int v);

private:
     int V;
     map<int, vector<Edge*>*>* adj;
};


#endif //ALGORITHMS_EDGEWEIGHTEDGRAPH_H
