//
// Created by Yariki on 9/17/2019.
//

#include "KruskalMST.h"
#include "../../union/QuickUnionUF.h"

KruskalMST::KruskalMST(EdgeWeightedGraph *graph) : graph(graph) {
    mst = new queue<Edge*>();

    auto edges = graph->edges();
    auto cmp = [](Edge* edge1, Edge* edge2) {
        return edge1->compareTo(edge2);
    };
    auto pq = new priority_queue<Edge*, vector<Edge*>, decltype(cmp)>(cmp);
    for (int i = 0; i < edges->size(); ++i) {
        pq->push(edges->at(i));
    }

    auto uf = new QuickUnionUF(graph->getV());

    while(!pq->empty() && mst->size() < (graph->getV() - 1)) {
        auto e = pq->top();
        pq->pop();
        int v = e->either(), w = e->other(v);
        if(uf->connected(v,w)){
            continue;
        }
        uf->union_(v,w);
        mst->push(e);
    }
}

KruskalMST::~KruskalMST() {
    delete graph;

}

queue<Edge *> *KruskalMST::edges() const {
    return mst;
}

double KruskalMST::weight() {
    return 0;
}
