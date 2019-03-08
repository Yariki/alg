//
// Created by Yariki on 3/8/2019.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "UndirectGraph.h"


void UndirectGraph::addEdge(int v, int w) {
    _map->at(v)->push_back(w);
    _map->at(w)->push_back(v);
}

