//
// Created by Yariki on 7/2/2017.
//

#ifndef ALGORITHMS_BSTNODE_H
#define ALGORITHMS_BSTNODE_H


class BSTNode {
public:
    BSTNode(int value);
    BSTNode(int value, BSTNode* parent,BSTNode* left, BSTNode* right);
    virtual ~BSTNode(){}

    int getValue() const {
        return value;
    }

    BSTNode *getParent() const {
        return parent;
    }

    BSTNode *getLeft() const {
        return left;
    }

    BSTNode *getRight() const {
        return right;
    }

    void setParent(BSTNode *parent);

    void setLeft(BSTNode *left);

    void setRight(BSTNode *right);


private:
    int value;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
};


#endif //ALGORITHMS_BSTNODE_H
