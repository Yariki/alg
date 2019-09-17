//
// Created by Yariki on 9/17/2019.
//

#include "MST.h"

MST::MST(EdgeWeightedGraph *graph) : graph(graph) {}

MST::~MST() {
    delete graph;
}

vector<Edge *> *MST::edges() {
    return nullptr;
}

double MST::weight() {
    return 0;
}
