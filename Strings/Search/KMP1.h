#ifndef __KMP1_H__
#define __KMP1_H__

#include <type_traits>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class KmpSearch {
public:
    KmpSearch(string filename);
    virtual ~KmpSearch();
    int search();

private:
    void fillDfa();
    void readFile(string filename);

private:
    string text;
    string pattern;
    int** dfa;
};

#endif // __KMP1_H__