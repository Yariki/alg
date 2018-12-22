//
// Created by Yariki on 12/22/2018.
//

#include "LLRBTree.h"


LLRBTree::LLRBTree() {

}

void LLRBTree::insert(int value) {
    root = insertInternal(root,value);
    root->setColor(Black);
}

RBNode *LLRBTree::insertInternal(RBNode* h, int value) {

    auto x = h;

    if(x == nullptr){
        return createNewNode(value);
    }

    if(value < x->getValue()){
        x->setLeft(insertInternal(x->getLeft(),value));
    } else if(value > x->getValue() ){
        x->setRight(insertInternal(x->getRight(),value));
    } else {
        x->setValue(value);
    }

    if(isRed(x->getRight()) && !isRed(x->getLeft())){
        x = leftRotate(x);
    }
    if(x->getLeft() && isRed(x->getLeft()->getLeft())){
        x = righRotate(x);
    }
    if(isRed(x->getLeft()) && isRed(x->getRight())){
        flipColors(x);

    }

    x->setN(size(x->getLeft()) + size(x->getRight()) + 1);

    return x;
}

bool LLRBTree::isRed(const RBNode *node) {
    if(node == nullptr) return false;
    return node->getColor() == Red;
}

const RBNode *LLRBTree::minimum(const RBNode *localRoot) {
    return nullptr;
}

const RBNode *LLRBTree::maximum(const RBNode *localRoot) {
    return nullptr;
}

const RBNode *LLRBTree::search(const RBNode *localRoot, int value) {
    return nullptr;
}

RBNode *LLRBTree::createNewNode(int value) {
    auto node =new RBNode(value);
    node->setColor(Red);
    return node;
}

RBNode* LLRBTree::leftRotate(RBNode *h) {
    auto x = h->getRight();
    h->setRight(x->getLeft());
    x->setLeft(h);
    x->setColor(h->getColor());
    h->setColor(Red);
    x->setN(h->getN());
    h->setN(1 + size(h->getLeft()) + size(h->getRight()));
    return x;
}

RBNode* LLRBTree::righRotate(RBNode *h) {
    auto x = h->getLeft();
    h->setLeft(x->getRight());
    x->setRight(h);
    x->setColor(h->getColor());
    h->setColor(Red);
    x->setN(h->getN());
    h->setN(1 + size(h->getLeft()) + size(h->getRight()));

    return x;
}

void LLRBTree::flipColors(RBNode *h) {
    h->setColor(Red);
    h->getLeft()->setColor(Black);
    h->getRight()->setColor(Black);
}

int LLRBTree::size(const RBNode *node) {
    if(node == nullptr){
        return 0;
    }
    return node->getN();
}
