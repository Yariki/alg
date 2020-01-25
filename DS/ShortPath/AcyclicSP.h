//
// Created by Yariki on 1/22/2020.
//

#ifndef ALGORITHMS_ACYCLICSP_H
#define ALGORITHMS_ACYCLICSP_H

#include <vector>
#include <string>
#include "EdgeWeightedDigraph.h"
#include "DirectedEdge.h"
#include "../Graph/Direct/Digraph.h"
#include "../Graph/TopologicalSort.h"


class AcyclicSP
{
private:
    vector<DirectedEdge*> edgeTo;
    vector<double> distTo;
    int source;

    EdgeWeightedDigraph* graph;
    Digraph* dgraph;
    TopologicalSort* topologicalSort;


    void init(string filename);

public:
    AcyclicSP(string filename, int s);
    ~AcyclicSP();
};

   

#endif //ALGORITHMS_ACYCLICSP_H
