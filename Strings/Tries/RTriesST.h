#ifndef __RTRIESST_H__
#define __RTRIESST_H__

#include <string>
#include <vector>
#include <map>
#include "..\..\Shared\shared.h"

using std::vector;
using std::string;
using std::map;



class RTNode;

class RTNode 
{
private:
    int value;
    RTNode* next[R];

public:
    RTNode() 
    {
        for (int i = 0; i < R; i++)
        {
            next[i] = nullptr;
        }
    }

    virtual ~RTNode()
    {
        for (int i = 0; i < R; i++)
        {
            delete next[i];
            next[i] = nullptr;
        }
    }

    void setValue(int val ) {value = val;}
    int getValue() {return value;}

    void setNext(int key, RTNode *node) 
    {
        next[key] = node;
    }

    RTNode* getNext(int key)
    {
        return next[key];
    }

    bool isNext(int key)
    {
        return getNext(key) != nullptr;
    }
};

class RTriesST
{
private:
    RTNode* root;
    map<string,int> values;

public:
    RTriesST(string filename);
    ~RTriesST();
    int get(string key);
    void put(string key, int value);

private:    
    void init(string filename);

    void initTries();

    RTNode* get(RTNode *node, string key, int d);
    RTNode* put(RTNode *node, string key, int value, int d);
    vector<string> split(const string &str);
};




#endif // __RTRIESST_H__