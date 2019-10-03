//
// Created by Yariki on 9/17/2019.
//

#ifndef ALGORITHMS_KRUSKALMST_H
#define ALGORITHMS_KRUSKALMST_H


#include <queue>
#include "EdgeWeightedGraph.h"

class KruskalMST {

public:
    KruskalMST(EdgeWeightedGraph *graph);
    virtual ~KruskalMST();

    queue<Edge*>* edges() const ;
    double weight();

private:
    EdgeWeightedGraph* graph;
    queue<Edge*>* mst;
};


#endif //ALGORITHMS_KRUSKALMST_H
