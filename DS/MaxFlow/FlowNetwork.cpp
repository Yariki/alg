//
// Created by Yariki on 2/2/2020.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "FlowNetwork.h"

FlowNetwork::FlowNetwork(std::string filename) {
    init(filename);
}

FlowNetwork::~FlowNetwork() {

}

void FlowNetwork::init(std::string filename) {
    std::string temp;
    std::ifstream file(filename);
    if(file.good() && file.is_open()){
        std::getline(file,temp);
        v = std::stoi(temp);
        std::getline(file,temp);
        e = std::stoi(temp);
        initGraph(v);

        for (int i = 0; i < e; ++i) {
            std::getline(file, temp);
            auto tokens = split(temp);

            if(tokens.size() > 1){
                auto source = std::stoi(tokens.at(0));
                auto to = std::stoi(tokens.at(1));
                auto weight = std::stod(tokens.at(2));
                addEdge(new FlowEdge(source,to,weight));
            }
        }
    }
}

void FlowNetwork::initGraph(int v) {
    adj = new std::map<int, std::vector<FlowEdge*>*>();
    for (int i = 0; i < v; ++i) {
        adj->insert(std::pair<int, std::vector<FlowEdge*>*>(i,new std::vector<FlowEdge*>));
    }
}

std::vector<std::string> FlowNetwork::split(const std::string &input) {
    std::string token;
    std::vector<std::string> tokens;
    char delim = ' ';
    std::istringstream tokenStrem(input);
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

std::vector<FlowEdge *> *FlowNetwork::getAdj(int v) {
    return adj->at(v);
}

std::vector<FlowEdge *> *FlowNetwork::edges() {
    return nullptr;
}

int FlowNetwork::getV() const {
    return v;
}

int FlowNetwork::getE() const {
    return e;
}
