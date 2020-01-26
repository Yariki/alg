//
// Created by Yariki on 1/26/2020.
//

#include "BellmanFordSP.h"
#include <limits>


BellmanFordSP::BellmanFordSP(EdgeWeightedDigraph* g, int s) : graph(g), edgeTo(g->getV()), distTo(g->getV())
{
    for (int j = 0; j < graph->getV(); ++j) {
        distTo[j] = numeric_limits<double>::max();
        edgeTo[j] = nullptr;
    }

    distTo[s] = 0.0;
    q.push(s);
    q.push(graph->getV());
    int N = 0;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        while(v == graph->getV())
        {
            if(N++ > graph->getV()) return;
            q.push(graph->getV());
            v = q.front(); q.pop();
        }
        auto edges = graph->getEdges(v);
        for (int i = 0; i < edges->size(); ++i) {
            auto edge = edges->at(i);
            int w = edge->getTo();
            int P = distTo[v] + edge->getWeight();
            if(P < distTo[w]){
                distTo[w] = P;
                edgeTo[w] = edge;
                q.push(w);
            }
        }
    }
}

BellmanFordSP::~BellmanFordSP(){

}


double BellmanFordSP::disTo( int V){
    return distTo.at(V);
}

bool BellmanFordSP::hasPathTo(int v) {
    return distTo[v] < numeric_limits<double >::max();
}

stack<DirectedEdge *>* BellmanFordSP::pathTo(int v) {
    if(!hasPathTo(v))
        return nullptr;
    auto path = new stack<DirectedEdge*>();

    for (DirectedEdge* e = edgeTo[v]; e != nullptr; e = edgeTo[e->getFrom()]) {
        path->push(e);
    }
    return path;
}
