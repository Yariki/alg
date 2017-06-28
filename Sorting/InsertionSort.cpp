//
// Created by yariki on 6/12/2016.
//

#include "InsertionSort.h"

void InsertionSort::Sort(int *arr, int length) {
    if(arr == nullptr || !length){
        return;
    }
    for (int j = 1; j < length;j++){
        auto key = arr[j];
        auto i = j - 1;
        while(i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i-=1;
        }
        arr[i+1] = key;
    }
}
