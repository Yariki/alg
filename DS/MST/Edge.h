//
// Created by Yariki on 9/15/2019.
//

#ifndef ALGORITHMS_EDGE_H
#define ALGORITHMS_EDGE_H


class Edge {
public:
    Edge(int v, int w, double weight);
    virtual ~Edge();

public:
    int either();
    int other(int vertex);
    bool compareTo(Edge* that);

    double getWeight() const;

private:
    int v,w;
    double weight;

};


#endif //ALGORITHMS_EDGE_H
