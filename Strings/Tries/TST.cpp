#include "TST.h"

#include <fstream>
#include <iostream>
#include <sstream>

template<typename T>
TSTNode<T>::TSTNode() {
    left = mid = right = nullptr;
}

template<typename T>
TSTNode<T>::~TSTNode() {
    left = mid = right = nullptr;
}
template<typename T>
void TSTNode<T>::setValue(const T val) {
    value = val;
}

template<typename T>
void TSTNode<T>::setKey(const char key) {
    this->key = key;
}

template<typename T>
T TSTNode<T>::getValue() {
    return value;
}

template<typename T>
char TSTNode<T>::getKey() {
    return key;
}

template<typename T>
TSTNode<T>* TSTNode<T>::getLeft() {
    return left;
}

template<typename T>
TSTNode<T>* TSTNode<T>::getMid()  {
    return mid;
}

template<typename T>
TSTNode<T>* TSTNode<T>::getRight()  {
    return right;
}

template<typename T>
void TSTNode<T>::setLeft( TSTNode<T> *val) {
    left = val;
}

template<typename T>
void TSTNode<T>::setMid( TSTNode<T> *val) {
    mid = val;
}

template<typename T>
void TSTNode<T>::setRight( TSTNode<T> *val) {
    right = val;
}

template<typename T>
TST<T>::TST(string filename)
{
    readFile(filename);
    init();
}

template<typename T>
TST<T>::~TST() {
}

template<typename T>
void TST<T>::readFile(string filename)
{
    string temp;
    std::ifstream file(filename);
    if(file.good() && file.is_open())
    {
        while(!file.eof())
        {
            std::getline(file, temp);
            auto tokens = split(temp);
            if(tokens.size() > 1)
            {
                auto key = tokens.at(0);
                auto val = std::stoi(tokens.at(1));
                values.insert(std::pair<string,int>(key,val));
            }
        }
    }
}

template<typename T>
vector<string> TST<T>::split(const string &input)
{
    string token;
    vector<string> tokens;
    char delim = ' ';
    std::istringstream tokenStrem(input);
    while (std::getline(tokenStrem,token,delim)){
        tokens.push_back(token);
    }
    return tokens;
}

template <typename  T>
void TST<T>::init()
{
    if(!values.size()) return;

    for(auto pair: values){
        std::cout << pair.first << ": " << pair.second << std::endl;
        put(pair.first,pair.second);
    }
}

template <typename T>
void TST<T>::put(string key, T val)
{
    root = put(root,key,val,0);
}


template <typename T>
TSTNode<T>* TST<T>::put(TSTNode<T> *node, string key, T val, int d)
{
    char ch = key[d];
    if(node == nullptr)
    {
        node = new TSTNode<int>();
        node->setKey(ch);
    }
    if(ch < node->getKey())
    {
        node->setLeft(put(node->getLeft(),key,val,d));
    }
    else if(ch > node->getKey())
    {
        node->setRight(put(node->getRight(),key,val,d));
    }
    else if(d < key.size() - 1)
    {
        node->setMid(put(node->getMid(),key,val,d+1));
    }
    else
    {
        node->setValue(val);
    }
    return node;
}

template <typename T>
T TST<T>::get(string key)
{
    TSTNode<T> *node = get(root,key,0);
    if(node == nullptr) return 0xDEADBEAF;
    return node->getValue();
}

template <typename T>
TSTNode<T>* TST<T>::get(TSTNode<T> *node, string key, int d)
{
    if(node == nullptr) return nullptr;
    char ch = key[d];
    if(ch < node->getKey())
        return get(node->getLeft(),key,d);
    else if(ch > node->getKey())
        return get(node->getRight(),key,d);
    else if(d < key.size() - 1)
        return get(node->getMid(),key,d+1);
    return node;
}

template class TSTNode<int>;
template class TST<int>;






