//
// Created by Yariki on 3/8/2019.
//

#include "Graph.h"
//
// Created by Yariki on 3/8/2019.
//

#include <fstream>
#include <iostream>
#include <sstream>

int Graph::getV() const {
    return V;
}

int Graph::getE() const {
    return E;
}

Graph::Graph() {

}

Graph::~Graph() {
    for(auto it = _map->begin(); it != _map->end(); it++){
        delete it->second;
    }
    delete _map;
}

void Graph::init(int v) {
    this->V = v;
    initGraph(V);
}

void Graph::init(string filename) {
    string temp;
    ifstream file(filename);
    if(file.good() && file.is_open()){
        getline(file,temp);
        V = stoi(temp);
        getline(file,temp);
        E = stoi(temp);
        initGraph(V);

        for (int i = 0; i < E; ++i) {
            getline(file, temp);
            auto tokens = split(temp);

            if(tokens.size() > 1){
                auto v = stoi(tokens.at(0));
                auto w = stoi(tokens.at(1));
                addEdge(v,w);
            }
        }

    }
}


vector<int> *Graph::adj(int v) {
    return _map->at(v);
}

void Graph::initGraph(int V) {
    _map = new map<int, vector<int>*>();

    for (int i = 0; i < V; ++i) {
        _map->insert(pair<int,vector<int>*>(i,new vector<int>));
    }
}

vector<string> Graph::split(const string &input) {
    string token;
    vector<string> tokens;
    char delim = ' ';
    istringstream tokenStrem(input);
    while (getline(tokenStrem,token,delim)){
        tokens.push_back(token);
    }

    return tokens;
}
