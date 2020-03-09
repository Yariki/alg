#ifndef _tst_h_
#define _tst_h_

#include <type_traits>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

template<typename T>
class TSTNode;


template<typename T>
class TSTNode 
{

static_assert(std::is_arithmetic<T>::value, "T must be numeric");

private:
    T value;
    char key;
    TSTNode<T> *left;
    TSTNode<T> *mid;
    TSTNode<T> *right;
public:
    TSTNode();
    virtual ~TSTNode();

    void setValue(const T val);
    T getValue();
    char getKey();
    void setKey(char key);
    void setLeft(TSTNode<T> *val);
    void setMid(TSTNode<T> *val);
    void setRight(TSTNode<T> *val);
    TSTNode<T>* getLeft();
    TSTNode<T>* getMid();
    TSTNode<T>* getRight();

};

template<typename T>
class TST 
{

static_assert(std::is_arithmetic<T>::value, "T must be numeric");

private:
    TSTNode<T> *root;
    map<string,T> values;

    void readFile(string filename);
    void init();
    void put(string key, T val);
    TSTNode<T>* put(TSTNode<T> *node, string key, T val, int d);
    TSTNode<T>* get(TSTNode<T> *node, string key, int d);
    vector<string> split(const string &str);

public:
    TST(string filename);
    virtual ~TST();
    T get(string key);
};

#endif // _tst_h_