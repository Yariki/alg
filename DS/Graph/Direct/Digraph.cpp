//
// Created by Yariki on 3/17/2019.
//

#include "Digraph.h"

void Digraph::addEdge(int v, int w) {
    _map->at(v)->push_back(w);
}

Digraph::Digraph() {}

Digraph::~Digraph() {

}
