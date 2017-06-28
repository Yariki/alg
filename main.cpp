#include <iostream>
#include "Sorting/InsertionSort.h"
#include "Sorting/MergeSort.h"
#include "Sorting/HeapSort.h"
#include "Sorting/QuickSort.h"

using namespace std;

int main() {
    int arr[10] = {4,1,3,2,16,9,10,14,8,7};
    //int arr[4] = {7,2,3,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sort\n");
    for (int i = 0; i < length; ++i) {
        printf("%d ",arr[i]);
    }
    auto sort = new HeapSort();
    sort->Sort(arr, length);
    printf("\nAfter Sort\n");
    for (int i = 0; i < length; ++i) {
        printf("%d ",arr[i]);
    }
    delete sort;
}