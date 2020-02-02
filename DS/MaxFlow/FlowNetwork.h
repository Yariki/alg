//
// Created by Yariki on 2/2/2020.
//

#ifndef ALGORITHMS_FLOWNETWORK_H
#define ALGORITHMS_FLOWNETWORK_H

#include <vector>
#include <map>
#include "FlowEdge.h"

using namespace std;

class FlowNetwork {
private:
    int v;
    int e;
    map<int, vector<FlowEdge*>*>* adj;

    void init(string filename);
    void initGraph(int v);
    vector<string> split(const string& input);

public:
    FlowNetwork(string filename);
    virtual ~FlowNetwork();
    void addEdge(FlowEdge* e);
    vector<FlowEdge*>* getAdj(int v);
    vector<FlowEdge*>* edges();
    int getV() const;
    int getE() const;

};


#endif //ALGORITHMS_FLOWNETWORK_H
