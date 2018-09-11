//
// Created by Yariki on 9/11/2018.
//

#include "Quick3WaySort.h"

Quick3WaySort::Quick3WaySort() {}

Quick3WaySort::~Quick3WaySort() {

}

void Quick3WaySort::Sort(int *arr, int length) {
    sort(arr, 0, length - 1);
}

void Quick3WaySort::sort(int *arr, int lo, int hi) {
    if(hi <= lo) return;
    int lt = lo, gt = hi;
    auto v = arr[lo];
    auto i = lo;
    while(i <= gt){
        if(arr[i] < v){
            auto temp = arr[i];
            arr[i] = arr[lt];
            arr[lt] = temp;
            lt++;
            i++;
        } else if (arr[i] > v) {
            auto temp = arr[gt];
            arr[gt] = arr[i];
            arr[i] = temp;
            gt--;
        }else{
            i++;
        }
    }
    sort(arr, lo, lt - 1);
    sort(arr, gt + 1, hi);
}
