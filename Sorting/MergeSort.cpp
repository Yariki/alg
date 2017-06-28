//
// Created by yariki on 6/25/2016.
//

#include "MergeSort.h"



void MergeSort::Sort(int *arr, int length) {
    //we pass the start index and finish index elements.
    Merge_Sort(arr,0,length-1);
}


void MergeSort::Merge_Sort(int* arr, int start, int end){
    if(start < end){
        auto middle = (start + (end - 1)) / 2;
        Merge_Sort(arr, start,middle);
        Merge_Sort(arr,middle+1,end);
        Merge(arr,start,middle,end);
    }
}

void MergeSort::Merge(int* arr, int start, int middle, int end){
    const int n1 = middle - start + 1;
    const int n2 = end - middle;
    int left[n1] = {};
    int right[n2] = {};
    for (int i = 0; i < n1; ++i) {
        left[i] = arr[start + i ];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = arr[ middle + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while(i < n1 && j < n2){
        if(left[i]  <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = left[i];
        i++;k++;
    }
    while(j < n2){
        arr[k] = right[j];
        j++;k++;
    }
}



