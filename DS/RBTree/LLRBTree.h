//
// Created by Yariki on 12/22/2018.
//

#ifndef ALGORITHMS_LLRBTREE_H
#define ALGORITHMS_LLRBTREE_H


#include "RBNode.h"

class LLRBTree {
public:
    LLRBTree();
    virtual ~LLRBTree(){}

public:
    RBNode *getRoot() const {
        return root;
    }

    RBNode *getNil() const {
        return nil;
    }
    void insert(int value);
    //void deleteNode(RBNode* z);
    const RBNode* minimum(const RBNode* localRoot);
    const RBNode* maximum(const RBNode* localRoot);
    const RBNode* search(RBNode* localRoot, int value);
    void deleteMax();
    void deleteMin();
    void deleteNode(int value);
private:
    RBNode *createNewNode(int value);
    RBNode* insertInternal(RBNode* h, int value);
    RBNode*  leftRotate(RBNode* x);
    RBNode* righRotate(RBNode* y);
    RBNode* fixUp(RBNode* h);
    RBNode* moveRedRight(RBNode* h);
    RBNode* moveRedLeft(RBNode* h);
    void flipColors(RBNode* h);
    bool isRed(const RBNode* node);
    int size(const RBNode* node);
    RBNode* deleteMax(RBNode* h);
    RBNode* deleteMin(RBNode* h);
    RBNode* deleteInternal(RBNode* localRoot, int value);
    bool isEmpty();

private:
    RBNode* root;
    RBNode* nil;
};


#endif //ALGORITHMS_LLRBTREE_H
