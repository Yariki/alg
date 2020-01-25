//
// Created by Yariki on 1/22/2020.
//

#ifndef ALGORITHMS_DIRECTEDEDGE_H
#define ALGORITHMS_DIRECTEDEDGE_H


class DirectedEdge {

public:
    DirectedEdge(int v, int w, double weight);
    virtual ~DirectedEdge();
    int getFrom() const;
    int getTo() const;
    double getWeight() const;

private:
    int v;
    int w;
    double weight;

};


#endif //ALGORITHMS_DIRECTEDEDGE_H
