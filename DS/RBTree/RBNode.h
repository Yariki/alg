//
// Created by Yariki on 7/6/2017.
//

#ifndef ALGORITHMS_RBNODE_H
#define ALGORITHMS_RBNODE_H

enum RBNODE_COLOR{
    Red,
    Black
};

class RBNode {

public:
    RBNode(){}
    RBNode(int value){
        this->value = value;
    }
    virtual ~RBNode(){
        left = right = parent = nullptr;
    }

    int getValue() const {
        return this->value;
    }

    void setValue(int value) {
        this->value = value;
    }

    RBNODE_COLOR getColor() const {
        return color;
    }

    void setColor(RBNODE_COLOR color) {
        this->color = color;
    }

    RBNode *getParent() const {
        return parent;
    }

    void setParent(RBNode *parent) {
        this->parent = parent;
    }

    RBNode *getLeft() const {
        return left;
    }

    void setLeft(RBNode *left) {
        this->left = left;
    }

    RBNode *getRight() const {
        return right;
    }

    void setRight(RBNode *right) {
        this->right = right;
    }


private:
    int value;
    RBNODE_COLOR color;
    RBNode* parent;
    RBNode* left;
    RBNode* right;
};


#endif //ALGORITHMS_RBNODE_H