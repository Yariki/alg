//
// Created by Yariki on 7/6/2017.
//

#ifndef ALGORITHMS_RBTREE_H
#define ALGORITHMS_RBTREE_H



#include "RBNode.h"


class RBTree {

public:
    RBTree();
    virtual ~RBTree(){}

public:
    RBNode *getRoot() const {
        return root;
    }

    RBNode *getNil() const {
        return nil;
    }
    void insert(int value);
    void deleteNode(RBNode* z);
    const RBNode* minimum(const RBNode* localRoot);
    const RBNode* maximum(const RBNode* localRoot);
    const RBNode* search(const RBNode* localRoot, int value);
    void display();
private:
    RBNode *createNewNode(int value);
    void leftRotate(RBNode* x);
    void righRotate(RBNode* y);
    void insertFixup(RBNode* z);
    void rbTransplant(RBNode* u, RBNode* v);
    void rbDeleteFixup(RBNode* x);
    void internalDisplay(RBNode* node);
    RBNode* treeSuccessor(RBNode* z);




private:
    RBNode* root;
    RBNode* nil;

};


#endif //ALGORITHMS_RBTREE_H
