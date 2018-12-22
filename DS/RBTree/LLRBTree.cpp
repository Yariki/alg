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
    auto local = localRoot == nullptr ? root : localRoot;
    while(local != nullptr){
        local = local->getLeft();
    }
    return local;
}

const RBNode *LLRBTree::maximum(const RBNode *localRoot) {
    return nullptr;
}

const RBNode *LLRBTree::search(RBNode* localRoot,int value) {
    auto local = localRoot == nullptr ? root : localRoot;
    while(local != nullptr){
        if(local->getValue() == value){
            return local;
        } else if(value > local->getValue()){
            local = local->getRight();
        } else if(value < local->getValue()){
            local = local->getLeft();
        }
    }
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

RBNode *LLRBTree::fixUp(RBNode *h) {
    auto x = h;
    if(isRed(x->getRight())){
        x = leftRotate(x);
    }
    if(isRed(x->getLeft()) && isRed(x->getLeft()->getLeft())){
        x = righRotate(x);
    }
    if(isRed(x->getLeft()) && isRed(x->getRight())){
        flipColors(x);
    }

    return x;
}

RBNode *LLRBTree::moveRedRight(RBNode *h) {
    auto x = h;
    flipColors(x);
    if(isRed(x->getLeft()->getLeft())){
        x = righRotate(x);
        flipColors(x);
    }
    return x;
}

RBNode *LLRBTree::moveRedLeft(RBNode *h) {
    auto x = h;
    flipColors(x);
    if(isRed(x->getRight()->getLeft())){
        x->setRight(righRotate(x->getRight()));
        x = leftRotate(x);
        flipColors(x);
    }
    return x;
}

void LLRBTree::deleteMax() {
    root = deleteMax(root);
    root->setColor(Black);
}

RBNode *LLRBTree::deleteMax(RBNode *h) {
    auto x = h;
    if(isRed(x->getLeft()))
        x = righRotate(x);

    if(x->getRight() == nullptr){
        return nullptr;
    }

    if(!isRed(x->getRight()) && !isRed(x->getRight()->getLeft()))
        x = moveRedRight(x);

    x->setLeft(deleteMax(x->getLeft()));

    return fixUp(x);
}

void LLRBTree::deleteMin() {
    root = deleteMin(root);
    root->setColor(Black);
}

RBNode *LLRBTree::deleteMin(RBNode *h) {
    auto x = h;
    if(x->getLeft() == nullptr){
        return nullptr;
    }
    if(!isRed(x->getLeft()) && !isRed(x->getLeft()->getLeft())){
        x = moveRedLeft(x);
    }
    x->setLeft(deleteMin(x->getLeft()));

    return fixUp(x);
}

void LLRBTree::deleteNode(int value) {

}
