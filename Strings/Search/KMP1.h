#ifndef __KMP1_H__
#define __KMP1_H__

#include <type_traits>
#include <string>
#include <vector>
#include <map>
#include "..\..\Shared\shared.h"

using std::map;
using std::vector;
using std::string;

class KmpSearch {
public:
    KmpSearch(string filename);
    virtual ~KmpSearch();
    int search();

private:
    void readFile(string filename);

private:
    string text;
    string pattern;
};

#endif // __KMP1_H__