//
// Created by Yariki on 2/2/2020.
//

#ifndef ALGORITHMS_FORDFULKERSON_H
#define ALGORITHMS_FORDFULKERSON_H

#include <vector>
#include "FlowEdge.h"
#include "FlowNetwork.h"

using namespace std;

class FordFulkerson {

private:
    vector<bool> marked;
    vector<FlowEdge*> edgeTo;
    double value;

public:

    FordFulkerson(FlowNetwork* network, int s, int t);
    virtual ~FordFulkerson();

    double hasAugmenticPath(FlowNetwork *network,int s, int t);
    double getValue();
    bool isCut(int v);

};


#endif //ALGORITHMS_FORDFULKERSON_H
