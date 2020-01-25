
#include "AcyclicSP.h"
#include <limits>

using namespace std;

AcyclicSP::AcyclicSP(string filename, int s): source(s)
{
    dgraph = new Digraph();
    dgraph->init(filename);
    topologicalSort = new TopologicalSort(dgraph);
    graph = new EdgeWeightedDigraph(filename);
    edgeTo = vector<DirectedEdge*>(graph->getV());
    distTo = vector<double>(graph->getV());
    for (int i = 0; i < edgeTo.size(); ++i) {
        edgeTo[i] = nullptr;
        distTo[i] = numeric_limits<double>::max();
    }
    distTo[s] = 0.0;

    auto order = topologicalSort->order();

    while(!order->empty()){
        auto top = order->top();
        order->pop();
        auto edges = graph->getEdges(top);

        for (int i = 0; i < edges->size(); ++i) {
            auto edge = edges->at(i);
            auto v = edge->getFrom();
            auto w = edge->getTo();

            if(distTo[w] > distTo[v] + edge->getWeight()){
                distTo[w] = distTo[v] + edge->getWeight();
                edgeTo[w] = edge;
            }
        }
    }
}

AcyclicSP::~AcyclicSP()
{
    delete graph;
    delete dgraph;
    delete topologicalSort;
}


double AcyclicSP::disTo(int v) {
    return distTo[v];
}

bool AcyclicSP::hasPathTo(int v) {
    return distTo[v] < numeric_limits<double >::max();
}

stack<DirectedEdge *>* AcyclicSP::pathTo(int v) {
    if(!hasPathTo(v))
        return nullptr;
    auto path = new stack<DirectedEdge*>();

    for (DirectedEdge* e = edgeTo[v]; e != nullptr; e = edgeTo[e->getFrom()]) {
        path->push(e);
    }
    return path;
}



 
