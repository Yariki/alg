//
// Created by Yariki on 2/2/2020.
//

#include "FlowEdge.h"

FlowEdge::FlowEdge(int v, int w, double capacity) : v(v), w(w), capacity(capacity) {}

FlowEdge::~FlowEdge() {

}

int FlowEdge::from() const {
    return v;
}

int FlowEdge::to() const {
    return w;
}

double FlowEdge::getCapacity() {
    return capacity;
}

double FlowEdge::getFlow() {
    return flow;
}

int FlowEdge::other(int vertex) {
    if(vertex == v) return w;
    if(vertex == w) return v;
    return -1;
}

double FlowEdge::residualCapacity(int vertex) {
    if(vertex == v) return flow;
    else if(vertex == w) return capacity - flow;
    throw;
}

void FlowEdge::addResidualFlowTo(int vertex, double delta) {
    if(vertex == v) flow -= delta;
    else if (vertex == w) flow += delta;
}
