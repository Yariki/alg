//
// Created by Yariki on 1/22/2020.
//

#ifndef ALGORITHMS_EDGEWEIGHTEDDIGRAPH_H
#define ALGORITHMS_EDGEWEIGHTEDDIGRAPH_H

#include <string>
#include "vector"
#include "map"
#include "DirectedEdge.h"

using namespace std;

class EdgeWeightedDigraph {

public:
    EdgeWeightedDigraph(string filename);
    virtual ~EdgeWeightedDigraph();

    int getV() const {return v;}
    int getE() const {return e;}

    vector<DirectedEdge*>* getEdges(int v)  {
        return adj->at(v);
    }

    void addEdge(DirectedEdge* edge){
        adj->at(edge->getFrom());
    }
private:
    void init(string filename);
    void initGraph(int v);
    vector<string> split(const string& tokens);

private:
    int v;
    int e;
    map<int, vector<DirectedEdge*>*>* adj;
};


#endif //ALGORITHMS_EDGEWEIGHTEDDIGRAPH_H
