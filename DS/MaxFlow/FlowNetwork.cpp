//
// Created by Yariki on 2/2/2020.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "FlowNetwork.h"

FlowNetwork::FlowNetwork(string filename) {
    init(filename);
}

FlowNetwork::~FlowNetwork() {

}

void FlowNetwork::init(string filename) {
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
                addEdge(new FlowEdge(source,to,weight));
            }
        }
    }
}

void FlowNetwork::initGraph(int v) {
    adj = new map<int,vector<FlowEdge*>*>();
    for (int i = 0; i < v; ++i) {
        adj->insert(pair<int,vector<FlowEdge*>*>(i,new vector<FlowEdge*>));
    }
}

vector<string> FlowNetwork::split(const string &input) {
    string token;
    vector<string> tokens;
    char delim = ' ';
    istringstream tokenStrem(input);
    while (getline(tokenStrem,token,delim)){
        tokens.push_back(token);
    }

    return tokens;
}

void FlowNetwork::addEdge(FlowEdge *e) {
    int v = e->from();
    int w = e->to();
    adj->at(v)->push_back(e);
    adj->at(w)->push_back(e);
}

vector<FlowEdge *> *FlowNetwork::getAdj(int v) {
    return adj->at(v);
}

vector<FlowEdge *> *FlowNetwork::edges() {
    return nullptr;
}

int FlowNetwork::getV() const {
    return v;
}

int FlowNetwork::getE() const {
    return e;
}
