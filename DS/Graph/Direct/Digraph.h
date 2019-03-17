//
// Created by Yariki on 3/17/2019.
//

#ifndef ALGORITHMS_DIGRAPH_H
#define ALGORITHMS_DIGRAPH_H


#include "../Graph.h"

class Digraph : public Graph{

public:
    Digraph();
    virtual ~Digraph();

public:
    void addEdge(int v, int w) override;

};


#endif //ALGORITHMS_DIGRAPH_H
