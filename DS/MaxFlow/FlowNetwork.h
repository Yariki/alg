//
// Created by Yariki on 2/2/2020.
//

#ifndef ALGORITHMS_FLOWNETWORK_H
#define ALGORITHMS_FLOWNETWORK_H

#include <string>
#include <vector>
#include <map>
#include "FlowEdge.h"



class FlowNetwork {
private:
    int v;
    int e;
    std::map<int, std::vector<FlowEdge*>*>* adj;

    void init(std::string filename);
    void initGraph(int v);
    std::vector<std::string> split(const std::string& input);

public:
    FlowNetwork(std::string filename);
    virtual ~FlowNetwork();
    void addEdge(FlowEdge* e);
    std::vector<FlowEdge*>* getAdj(int v);
    std::vector<FlowEdge*>* edges();
    int getV() const;
    int getE() const;

};


#endif //ALGORITHMS_FLOWNETWORK_H
