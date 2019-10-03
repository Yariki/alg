//
// Created by Yariki on 9/15/2019.
//

#include "Edge.h"

Edge::~Edge() {

}

Edge::Edge(int v, int w, double weight):v(v),w(w),weight(weight){
}

int Edge::either() {
    return v;
}

int Edge::other(int vertex) {
    return vertex == v ? w : v;
}

bool Edge::compareTo(Edge *that) {
    return this->getWeight() > that->getWeight();
}

double Edge::getWeight() const {
    return weight;
}



