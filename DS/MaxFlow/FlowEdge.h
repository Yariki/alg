//
// Created by Yariki on 2/2/2020.
//

#ifndef ALGORITHMS_FLOWEDGE_H
#define ALGORITHMS_FLOWEDGE_H


class FlowEdge {
private:
    int v, w;
    double capacity;
    double flow;

public:
    FlowEdge(int v, int w, double capacity);
    virtual ~FlowEdge();
    int from() const;
    int to() const;
    double getCapacity();
    double getFlow();
    int other(int vertex);

    double residualCapacity(int vertex);
    void addResidualFlowTo(int vertex, double delta);
};


#endif //ALGORITHMS_FLOWEDGE_H
