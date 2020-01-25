//
// Created by Yariki on 1/22/2020.
//

#include "DirectedEdge.h"

DirectedEdge::DirectedEdge(int v, int w, double weight) : v(v), w(w), weight(weight) {}

DirectedEdge::~DirectedEdge() {

}

int DirectedEdge::getFrom() const {
    return v;
}

int DirectedEdge::getTo() const {
    return w;
}

double DirectedEdge::getWeight() const {
    return weight;
}
