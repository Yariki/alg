//
// Created by Yariki on 1/26/2020.
//

#ifndef ALGORITHMS_BELLMANFORDSP_H
#define ALGORITHMS_BELLMANFORDSP_H


#include <vector>
#include <queue>
#include <stack>
#include "DirectedEdge.h"
#include "EdgeWeightedDigraph.h"

using namespace std;


class BellmanFordSP {

    private:
        EdgeWeightedDigraph* graph;
        vector<DirectedEdge*> edgeTo;
        vector<double> distTo;
        queue<int> q;

        
    public:
        BellmanFordSP(EdgeWeightedDigraph* g, int s);
        virtual ~BellmanFordSP();
        double disTo(int v);
        bool hasPathTo(int v);
        stack<DirectedEdge*>* pathTo(int v);

};


#endif //ALGORITHMS_BELLMANFORDSP_H
