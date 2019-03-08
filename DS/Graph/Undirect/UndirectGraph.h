//
// Created by Yariki on 3/8/2019.
//

#ifndef ALGORITHMS_UNDIRECTGRAPH_H
#define ALGORITHMS_UNDIRECTGRAPH_H


using namespace std;

#include "../Graph.h"

class UndirectGraph : public Graph{

public:
    UndirectGraph(): Graph(){}
    virtual ~UndirectGraph() {}

public:
    virtual void addEdge(int v, int w);

};


#endif //ALGORITHMS_UNDIRECTGRAPH_H
