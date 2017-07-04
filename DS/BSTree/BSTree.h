//
// Created by Yariki on 7/2/2017.
//

#ifndef ALGORITHMS_BSTREE_H
#define ALGORITHMS_BSTREE_H


#include "BSTNode.h"

class BSTree {

public:
    BSTree();
    virtual ~BSTree();

    BSTNode* getRoot() const;
    void insertNode(int value);
    void deleteNode(int value);


    const BSTNode* search(const BSTNode* localRoot, int value);
    const BSTNode* minimum(const BSTNode* localRoot);
    const BSTNode* maximum(const BSTNode* localRoot);

private:
    void transplant(BSTNode* u, BSTNode* v);

private:
    BSTNode* root;


};


#endif //ALGORITHMS_BSTREE_H
