//
// Created by Yariki on 1/23/2020.
//

#include "DijkstraSP.h"
#include <limits>

DijkstraSP::DijkstraSP(EdgeWeightedDigraph *graph, int s) : graph(graph), distTo(graph->getV()), edgeTo(graph->getV()) {

    pq = new Pq(graph->getV(),false);
    for (int i = 0; i < distTo.size(); ++i) {
        distTo[i] = numeric_limits<double>::max();
    }
    distTo[s] = 0.0;
    edgeTo[s] = nullptr;
    pq->insert(new Bucket(0.0,s));

    while(!pq->isEmpty()){
        auto buck = pq->getTop();
        relax(graph,buck->getValue());
        delete buck;
    }
}

void DijkstraSP::relax(EdgeWeightedDigraph *graph, int v) {
    vector<DirectedEdge*>* edges = graph->getEdges(v);
    for (int i = 0; i < edges->size(); ++i) {
        auto edge = edges->at(i);
        int w = edge->getTo();

        if(distTo[w] > distTo[v] + edge->getWeight()){
            distTo[w]  = distTo[v] + edge->getWeight();
            edgeTo[w] = edge;
            pq->insert(new Bucket(distTo[w],w));
        }
    }
}

DijkstraSP::~DijkstraSP() {
    delete pq;
}

double DijkstraSP::disTo(int v) {
    return distTo[v];
}

bool DijkstraSP::hasPathTo(int v) {
    return distTo[v] < numeric_limits<double >::max();
}

stack<DirectedEdge *> DijkstraSP::pathTo(int v) {
    if(!hasPathTo(v))
        return stack<DirectedEdge *>();
    stack<DirectedEdge*> path;

    for (DirectedEdge* e = edgeTo[v]; e != nullptr; e = edgeTo[e->getFrom()]) {
        path.push(e);
    }
    return path;
}

