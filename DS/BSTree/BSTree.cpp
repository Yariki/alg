//
// Created by Yariki on 7/2/2017.
//

#include "BSTree.h"

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {

}

void BSTree::insertNode(int value) {
    auto node = new BSTNode(value);
    BSTNode* y = nullptr;
    BSTNode*  x = root;

    while(x != nullptr){
        y = x;
        if(value < x->getValue()){
            x = x->getLeft();
        }else{
            x = x->getRight();
        }
    }
    node->setParent(y);
    if(y == nullptr){
        root = node;
    }else if(node->getValue() < y->getValue()){
        y->setLeft(node);
    }else{
        y->setRight(node);
    }
}

BSTNode *BSTree::getRoot() const {
    return BSTree::root;
}

const BSTNode * BSTree::minimum(const BSTNode *localRoot) {
    auto local = localRoot;
    while(local->getLeft() != nullptr){
        local = local->getLeft();
    }
    return local;
}

const BSTNode * BSTree::maximum(const BSTNode *localRoot) {
    auto local = localRoot;
    while(local->getRight() != nullptr){
        local = local->getRight();
    }
    return local;
}

const BSTNode *BSTree::search(const BSTNode *localRoot, int value) {
    auto local = localRoot;
    if(local == nullptr || value  == local->getValue()){
        return local;
    }
    if(value < local->getValue()){
        search(local->getLeft(),value);
    }else{
        search(local->getRight(),value);
    }
}

void BSTree::deleteNode(int value) {

}
