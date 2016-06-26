#include <iostream>
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

int main() {
    int arr[10] = {3,1,7,9,2,8,4,5,6,0};
    //int arr[4] = {7,2,3,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    auto sort = new MergeSort();
    sort->Sort(arr, length);
    for (int i = 0; i < length; ++i) {
        printf("%d ",arr[i]);
    }
    delete sort;
}