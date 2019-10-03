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
    EdgeWeightedGraph(string filename);
    virtual ~EdgeWeightedGraph();

public:
    void  addEdge(Edge* e);
    vector<Edge*>* edges();
    vector<Edge*>* edges(int v);

    int getV() const;

    int getE() const;

private:
    void initGraph(int v);
    void init(string filename);
    vector<string> split(const string& input);

private:
     int V;
     int E;
     map<int, vector<Edge*>*>* adj;
};


#endif //ALGORITHMS_EDGEWEIGHTEDGRAPH_H
