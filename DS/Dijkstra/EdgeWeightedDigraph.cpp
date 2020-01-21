//
// Created by Yariki on 1/22/2020.
//

#include "EdgeWeightedDigraph.h"
#include <fstream>
#include <iostream>
#include <sstream>

EdgeWeightedDigraph::EdgeWeightedDigraph(string filename) {

}

EdgeWeightedDigraph::~EdgeWeightedDigraph() {

}

void EdgeWeightedDigraph::init(string filename) {
    string temp;
    ifstream file(filename);
    if(file.good() && file.is_open()){
        getline(file,temp);
        v = stoi(temp);
        getline(file,temp);
        e = stoi(temp);
        initGraph(v);

        for (int i = 0; i < e; ++i) {
            getline(file, temp);
            auto tokens = split(temp);

            if(tokens.size() > 1){
                auto source = stoi(tokens.at(0));
                auto to = stoi(tokens.at(1));
                auto weight = stod(tokens.at(2));
                addEdge(new DirectedEdge(source,to,weight));
            }
        }
    }
}

void EdgeWeightedDigraph::initGraph(int v) {
    adj = new map<int,vector<DirectedEdge*>*>();
    for (int i = 0; i < v; ++i) {
        adj->insert(pair<int,vector<DirectedEdge*>*>(i,new vector<DirectedEdge*>));
    }
}

vector<string> EdgeWeightedDigraph::split(const string &input) {
    string token;
    vector<string> tokens;
    char delim = ' ';
    istringstream tokenStrem(input);
    while (getline(tokenStrem,token,delim)){
        tokens.push_back(token);
    }

    return tokens;
}

