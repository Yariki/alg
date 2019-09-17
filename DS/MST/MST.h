//
// Created by Yariki on 9/17/2019.
//

#ifndef ALGORITHMS_MST_H
#define ALGORITHMS_MST_H


#include "EdgeWeightedGraph.h"

class MST {

public:
    MST(EdgeWeightedGraph *graph);
    virtual ~MST();

    vector<Edge*>* edges();
    double weight();

private:
    EdgeWeightedGraph* graph;
};


#endif //ALGORITHMS_MST_H
