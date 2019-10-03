//
// Created by Yariki on 9/15/2019.
//

#include "EdgeWeightedGraph.h"
#include <fstream>
#include <iostream>
#include <sstream>

EdgeWeightedGraph::EdgeWeightedGraph(int v) : V(v) {
    initGraph(V);
}

EdgeWeightedGraph::EdgeWeightedGraph(string filename) {
    init(filename);
}

EdgeWeightedGraph::~EdgeWeightedGraph() {
    for (int i = 0; i < V; ++i) {
        delete adj->at(i);
    }
    delete adj;
}

void EdgeWeightedGraph::addEdge(Edge *e) {
    auto v = e->either();
    auto w = e->other(v);
    auto vec = adj->at(v);
    adj->at(v)->push_back(e);
    adj->at(w)->push_back(e);

}

vector<Edge*> *EdgeWeightedGraph::edges(int v) {
    return adj->at(v);
}

vector<Edge *> *EdgeWeightedGraph::edges() {
    auto e = new vector<Edge*>();
    for(auto i = 0; i < V; i++){
        auto edg = adj->at(i);
        for(auto j = 0; j < edg->size();j++){
            if(edg->at(j)->other(i) > i){
                e->push_back(edg->at(j));
            }
        }
    }
    return e;
}

void EdgeWeightedGraph::init(string filename) {
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
                auto weight = stod(tokens.at(2));
                addEdge(new Edge(v,w,weight));
            }
        }
    }
}

void EdgeWeightedGraph::initGraph(int v) {
    adj = new map<int,vector<Edge*>*>();
    for (int i = 0; i < v; ++i) {
        adj->insert(pair<int,vector<Edge*>*>(i,new vector<Edge*>));
    }
}

vector<string> EdgeWeightedGraph::split(const string &input) {
    string token;
    vector<string> tokens;
    char delim = ' ';
    istringstream tokenStrem(input);
    while (getline(tokenStrem,token,delim)){
        tokens.push_back(token);
    }

    return tokens;
}

int EdgeWeightedGraph::getV() const {
    return V;
}

int EdgeWeightedGraph::getE() const {
    return E;
}
