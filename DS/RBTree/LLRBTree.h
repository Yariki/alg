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
    const RBNode* search(const RBNode* localRoot, int value);
private:
    RBNode *createNewNode(int value);
    RBNode* insertInternal(RBNode* h, int value);
    RBNode*  leftRotate(RBNode* x);
    RBNode* righRotate(RBNode* y);
    void flipColors(RBNode* h);
    bool isRed(const RBNode* node);
    int size(const RBNode* node);

private:
    RBNode* root;
    RBNode* nil;
};


#endif //ALGORITHMS_LLRBTREE_H
