//
// Created by Yariki on 6/28/2017.
//

#include "QuickSort.h"

void QuickSort::Sort(int *arr, int length) {
    QuickSorting(arr, 0, length - 1);
}

void QuickSort::QuickSorting(int *arr, int low, int hight) {
    if(low > hight)
        return;

    int mid = low + (hight - low) / 2;
    int pivot = arr[mid];
    int i = low;
    int j = hight;

    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if(low < j){
        QuickSorting(arr,low,j);
    }
    if(hight > i){
        QuickSorting(arr,i,hight);
    }

}
