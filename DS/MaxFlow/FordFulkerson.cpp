//
// Created by Yariki on 2/2/2020.
//

#include "FordFulkerson.h"
#include <limits>
#include <queue>
#include <deque>


FordFulkerson::FordFulkerson(FlowNetwork *network, int s, int t) {
    value = 0;
    while (hasAugmenticPath(network,s, t) > 0){
        double bottle = numeric_limits<double>::max();
        for(int v = t; v != s; v = edgeTo[v]->other(v)){
            if(edgeTo[v] == NULL) continue;
            bottle = std::min(bottle, edgeTo[v]->residualCapacity(v));
        }
        for (int v = t; v != s ; v = edgeTo[v]->other(v)) {
            if(edgeTo[v] == NULL) continue;
            edgeTo[v]->addResidualFlowTo(v,bottle);
        }
        value += bottle;
    }
}

FordFulkerson::~FordFulkerson() {

}

double FordFulkerson::hasAugmenticPath(FlowNetwork *network, int s, int t) {
    edgeTo = vector<FlowEdge*>(network->getV());
    marked = vector<bool>(network->getV());

    deque<int> q;
    q.push_back(s);

    while (!q.empty()){
        int v = q.front();
        q.pop_front();
        auto edges = network->getAdj(v);
        for (int i = 0; i < edges->size(); ++i) {
            auto edge = edges->at(i);
            int w = edge->other(v);
            if(edge->residualCapacity(w) > 0 && !marked[w]){
                edgeTo[w] = edge;
                marked[w] = true;
                q.push_back(w);
            }
        }
    }
    return marked[t];
}

double FordFulkerson::getValue() {
    return value;
}

bool FordFulkerson::isCut(int v) {
    return marked[v];
}
