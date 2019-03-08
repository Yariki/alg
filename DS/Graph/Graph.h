//
// Created by Yariki on 3/8/2019.
//

#ifndef ALGORITHMS_GRAPH_H
#define ALGORITHMS_GRAPH_H

using namespace std;

#include <string>
#include <vector>
#include <map>

class Graph {
public:
    Graph();
    virtual ~Graph();

public:
    vector<int> * adj(int v);
    int getV() const;
    int getE() const;
    void init(int v);
    void init(string filename);

public:
    virtual void addEdge(int v, int w) = 0;

private:
    void initGraph(int V);
    vector<string> split(const string& input);

private:
    int V;
    int E;
    string _filename;

protected:
    map<int,vector<int>*> *_map;

};


#endif //ALGORITHMS_GRAPH_H
