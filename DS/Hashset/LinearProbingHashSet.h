//
// Created by Yariki on 2/20/2019.
//

#ifndef ALGORITHMS_LINEARPROBINGHASHSET_H
#define ALGORITHMS_LINEARPROBINGHASHSET_H

#include <vector>

class LPNode {
public:
    LPNode(char _key, int _value, bool _isDeleted);

    virtual ~LPNode();

    char get_key() const;

    void set_key(char _key);

    int get_value() const;

    void set_value(int _value);

    bool is_isDeleted() const;

    void set_isDeleted(bool _isDeleted);


private:
    char _key;
    int _value;
    bool _isDeleted;
};

class LinearProbingHashSet {

public:
    LinearProbingHashSet();
    LinearProbingHashSet(int cap);

    virtual ~LinearProbingHashSet();

    void put(char key, int value);
    int get(char key);
private:
    int hash(char ch);
    void resize(int cap);
    void deleteBuckets(std::vector<LPNode*> *bucket);
private:
    std::vector<LPNode*> * _bucket;
    int n;
    int M;

};


#endif //ALGORITHMS_LINEARPROBINGHASHSET_H
