//
// Created by Yariki on 9/15/2019.
//

#include "EdgeWeightedGraph.h"

EdgeWeightedGraph::EdgeWeightedGraph(int v) : V(v) {
    adj = new map<int,vector<Edge*>*>();
    for (int i = 0; i < V; ++i) {
        adj->insert(pair<int,vector<Edge*>*>(i,new vector<Edge*>));
    }
}

EdgeWeightedGraph::~EdgeWeightedGraph() {
    for (int i = 0; i < V; ++i) {
        delete adj->at(i);
    }
    delete adj;
}

void EdgeWeightedGraph::addEdge(Edge *e) {
    auto v = e->either();
    auto w = e->other(v);
    auto vec = adj->at(v);
    adj->at(v)->push_back(e);
    adj->at(w)->push_back(e);

}

vector<Edge*> *EdgeWeightedGraph::edges(int v) {
    return adj->at(v);
}
