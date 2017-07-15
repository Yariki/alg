//
// Created by Yariki on 7/6/2017.
//

#include "RBTree.h"

RBTree::RBTree() {
    root = nullptr;
    nil = new RBNode();
    nil->setLeft(nullptr);
    nil->setRight(nullptr);
    nil->setColor(RBNODE_COLOR::Black);
}


void RBTree::leftRotate(RBNode *x) {
    auto y = x->getRight();
    x->setRight(y->getLeft());

    if(y->getLeft() != RBTree::nil){
        y->getLeft()->setParent(x);
    }
    y->setParent(x->getParent());
    if(x->getParent() == RBTree::nil){
        RBTree::root = y;
    }else if(x == x->getParent()->getLeft()){
        x->getParent()->setLeft(y);
    }else{
        x->getParent()->setRight(y);
    }
    y->setLeft(x);
    x->setParent(y);
}

void RBTree::righRotate(RBNode *y) {
    auto x = y->getLeft();
    y->setLeft(x->getRight());

    if(x->getRight() != RBTree::nil){
        x->getRight()->setParent(y);
    }
    x->setParent(y->getParent());
    if(y->getParent() == RBTree::nil){
        RBTree::root = x;
    }else if(y == y->getParent()->getLeft()){
        y->getParent()->setLeft(x);
    }else{
        y->getParent()->setRight(x);
    }
    x->setRight(y);
    y->setParent(x);
}

void RBTree::insert(int value) {
    auto z = createNewNode(value);
    auto y = RBTree::nil;
    auto x = root;
    while(x != RBTree::nil){
        y = x;
        if(z->getValue() < x->getValue()){
            x = x->getLeft();
        }else{
            x = x->getRight();
        }
    }
    z->setParent(y);
    if(y == RBTree::nil){
        RBTree::root = y;
    }else if(z->getValue() < y->getValue()){
        y->setLeft(z);
    }else{
        y->setRight(z);
    }
    insertFixup(z);
}

RBNode *RBTree::createNewNode(int value) {
    auto result = new RBNode(value);
    result->setParent(RBTree::nil);
    result->setRight(RBTree::nil);
    result->setLeft(RBTree::nil);
    result->setColor(RBNODE_COLOR::Red);
    return nullptr;
}

void RBTree::insertFixup(RBNode *z) {
    while(z->getParent()->getColor() == RBNODE_COLOR::Red){
        if(z->getParent() == z->getParent()->getParent()->getLeft()){
            auto y = z->getParent()->getParent()->getRight();
            if(y->getColor() == RBNODE_COLOR::Red){
                z->getParent()->setColor(RBNODE_COLOR::Black);
                y->setColor(RBNODE_COLOR::Black);
                z->getParent()->getParent()->setColor(RBNODE_COLOR::Red);
                z = z->getParent()->getParent();
            }else if(z == z->getParent()->getRight()){
                z = z->getParent();
                leftRotate(z);
            }
            z->getParent()->setColor(RBNODE_COLOR::Black);
            z->getParent()->getParent()->setColor(RBNODE_COLOR::Red);
            righRotate(z);
        }else{
            auto y = z->getParent()->getParent()->getLeft();
            if(y->getColor() == RBNODE_COLOR::Red){
                z->getParent()->setColor(RBNODE_COLOR::Black);
                y->setColor(RBNODE_COLOR::Black);
                z->getParent()->getParent()->setColor(RBNODE_COLOR::Red);
                z = z->getParent()->getParent();
            }else if(z == z->getParent()->getLeft()){
                z = z->getParent();
                righRotate(z);
            }
            z->getParent()->setColor(RBNODE_COLOR::Black);
            z->getParent()->getParent()->setColor(RBNODE_COLOR::Red);
            leftRotate(z);
        }
    }
    root->setColor(RBNODE_COLOR::Black);
}

void RBTree::deleteNode(RBNode *z) {
    auto y = z;
    auto yOriginalColor = y->getColor();
    RBNode* x = nullptr;
    if(z->getLeft() == RBTree::nil){
        x = z->getRight();
        rbTransplant(z,z->getRight());
    }else if(x->getRight() == RBTree::nil){
        x = z->getLeft();
        rbTransplant(z,z->getLeft());
    }else{
        y = (RBNode*)minimum(z->getRight());
        yOriginalColor = y->getColor();
        x = y->getRight();
        if(y->getParent() == z){
            x->setParent(y);
        }else{
            rbTransplant(y,y->getRight());
            y->setRight(z->getRight());
            y->getRight()->setParent(y);
        }
        rbTransplant(z,y);
        y->setLeft(z->getLeft());
        y->getLeft()->setParent(y);
        y->setColor(z->getColor());
    }
    if(yOriginalColor == RBNODE_COLOR::Black){
        rbDeleteFixup(x);
    }
}

void RBTree::rbTransplant(RBNode *u, RBNode *v) {
     if(u->getParent() == nil){
         root = v;
     } else if(u == u->getParent()->getLeft()){
        u->getParent()->setLeft(v);
     }else{
         u->getParent()->setRight(v);
     }
     v->setParent(u->getParent());
}

void RBTree::rbDeleteFixup(RBNode *x) {
    RBNode* w = nullptr;

    while(x != RBTree::root && x->getColor() == RBNODE_COLOR::Black){
        if(x == x->getParent()->getLeft()){
            w = x->getParent()->getRight();
            if(w->getColor() == RBNODE_COLOR::Red){
                w->setColor(RBNODE_COLOR::Black);
                x->getParent()->setColor(RBNODE_COLOR::Red);
                leftRotate(x->getParent());
                w = x->getParent()->getRight();
            }
            if(w->getLeft()->getColor() == RBNODE_COLOR::Black && w->getRight()->getColor() == RBNODE_COLOR::Black){
                w->setColor(RBNODE_COLOR::Black);
                x = x->getParent();
            }else if(w->getRight()->getColor() == RBNODE_COLOR::Black){
                w->getLeft()->setColor(RBNODE_COLOR::Black);
                w->setColor(RBNODE_COLOR::Red);
                righRotate(w);
                w = x->getParent()->getRight();
            }
            w->setColor(x->getParent()->getColor());
            x->getParent()->setColor(RBNODE_COLOR::Black);
            w->getRight()->setColor(RBNODE_COLOR::Black);
            leftRotate(x->getParent());
            x = RBTree::root;
        }else{
            // if right child
            w = x->getParent()->getLeft();
            if(w->getColor() == RBNODE_COLOR::Red){
                w->setColor(RBNODE_COLOR::Black);
                x->getParent()->setColor(RBNODE_COLOR::Red);
                righRotate(x->getParent());
                w = x->getParent()->getLeft();
            }
            if(w->getLeft()->getColor() == RBNODE_COLOR::Black && w->getRight()->getColor() == RBNODE_COLOR::Black){
                w->setColor(RBNODE_COLOR::Black);
                x = x->getParent();
            }else if(w->getLeft()->getColor() == RBNODE_COLOR::Black){
                w->getRight()->setColor(RBNODE_COLOR::Black);
                w->setColor(RBNODE_COLOR::Red);
                leftRotate(w);
                w = x->getParent()->getLeft();
            }
            w->setColor(x->getParent()->getColor());
            x->getParent()->setColor(RBNODE_COLOR::Black);
            w->getLeft()->setColor(RBNODE_COLOR::Black);
            righRotate(x->getParent());
            x = RBTree::root;
        }
        x->setColor(RBNODE_COLOR::Black);
    }
}

const RBNode *RBTree::minimum(const RBNode *localRoot) {
    auto local = localRoot;
    while(local->getLeft() != nullptr){
        local = local->getLeft();
    }
    return local;
}

const RBNode *RBTree::maximum(const RBNode *localRoot) {
    auto local = localRoot;
    while(local->getRight() != nullptr){
        local = local->getRight();
    }
    return local;
}

