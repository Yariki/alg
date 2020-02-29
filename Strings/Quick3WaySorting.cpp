//
// Created by Yariki on 2/29/2020.
//

#include "Quick3WaySorting.h"
#include <fstream>
#include <iostream>
#include <memory.h>

Quick3WaySorting::Quick3WaySorting(string filename) {
    init(filename);
}

Quick3WaySorting::~Quick3WaySorting() {

}

void Quick3WaySorting::init(string filename) {
    std::ifstream file(filename);
    if(file.good() && file.is_open()){
        string line;
        std::getline(file, line);
        strings.push_back(line);

        while(!file.eof()){
            std::getline(file,line);
            strings.push_back(line);
        }
        file.close();
    }
}

void Quick3WaySorting::sort(vector<string> &arr, int lo, int hi, int d) {
    if(hi <= lo) return;

    int lt = lo, gt = hi;
    int v = charAt(strings[lo],d);
    int i = lo + 1;
    while (i <= gt){
        int t = charAt(strings[i],d);
        if(t < v)
            exch(strings,lt++,i++);
        else if(t > v)
            exch(strings,i,gt--);
        else
            i++;
    }
    sort(strings,lo,lt-1,d);
    if(v >= 0) sort(strings,lt,gt,d+1);
    sort(strings,gt+1,hi,d);
}

int Quick3WaySorting::charAt(string &str, int d) {
    return d < str.size() ? str[d] : -1;
}

vector<string> Quick3WaySorting::sort() {
    sort(strings,0,strings.size() - 1, 0);
    return strings;
}

void Quick3WaySorting::exch(vector<string> &arr, int a, int b) {
    auto temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
