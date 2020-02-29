//
// Created by Yariki on 2/29/2020.
//

#ifndef ALGORITHMS_QUICK3WAYSORTING_H
#define ALGORITHMS_QUICK3WAYSORTING_H


#include <string>
#include <vector>

using std::string;
using std::vector;


class Quick3WaySorting {
private:
    vector<string> strings;

    void init(string filename);
    void sort(vector<string> &arr, int lo, int hi, int d);
    int charAt(string &str, int d);
    void exch(vector<string> &arr, int a, int b);

public:
    Quick3WaySorting(string filename);
    virtual ~Quick3WaySorting();
    vector<string> sort();

};


#endif //ALGORITHMS_QUICK3WAYSORTING_H
