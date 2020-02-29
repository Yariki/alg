#include "RTriesST.h"
#include <fstream>
#include <iostream>
#include <sstream>


RTriesST::RTriesST(string filename)
{
    root = nullptr;
    init(filename);
    initTries();
    
}

RTriesST::~RTriesST()
{
}

void RTriesST::init(string filename)
{
    string temp;
    std::ifstream file(filename);
    if(file.good() && file.is_open()){
        while(!file.eof()) {
            std::getline(file, temp);
            auto tokens = split(temp);
            if(tokens.size() > 1){
                auto key = tokens.at(0);
                auto val = std::stoi(tokens.at(1));
                values.insert(std::pair<string,int>(key,val));
            }
        }
    }
}

vector<string> RTriesST::split(const string &input) {
    string token;
    vector<string> tokens;
    char delim = ' ';
    std::istringstream tokenStrem(input);
    while (std::getline(tokenStrem,token,delim)){
        tokens.push_back(token);
    }
    return tokens;
}

void RTriesST::initTries()
{
    if(!values.size()) return;

    for(auto pair: values){
        std::cout << pair.first << ": " << pair.second << std::endl;
        put(pair.first,pair.second);
    }
}

int RTriesST::get(string key)
{
    RTNode* node = get(root, key, 0);
    if(node == nullptr) return 0xDEADBEAF;
    return node->getValue();
}

void RTriesST::put(string key, int value)
{
    root = put(root, key,value, 0);
}

RTNode* RTriesST::get(RTNode *node, string key, int d)
{
    if(node == nullptr) return nullptr;
    if(d == key.size()) return node;
    int c = key[d];
    return get(node->getNext(c),key, d + 1);
}

RTNode* RTriesST::put(RTNode *node, string key, int value, int d)
{
    if(node == nullptr)
        node = new RTNode();
    if(d == key.size()) 
    {
        node->setValue(value);
        return node;
    }    
    int c = key[d];
    node->setNext(c, put(node->getNext(c), key, value, d + 1));
    return node;
}

