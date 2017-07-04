//
// Created by Yariki on 7/2/2017.
//

#include "BSTNode.h"

BSTNode::BSTNode(int value) {
    this->value = value;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

BSTNode::BSTNode(int value, BSTNode *parent, BSTNode *left, BSTNode *right){
    this->value = value;
    this->parent = parent;
    this->left = left;
    this->right = right;
}

void BSTNode::setParent(BSTNode *parent) {
    BSTNode::parent = parent;
}

void BSTNode::setLeft(BSTNode *left) {
    BSTNode::left = left;
}

void BSTNode::setRight(BSTNode *right) {
    BSTNode::right = right;
}
