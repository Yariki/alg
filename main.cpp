#include <iostream>
#include "Sorting/InsertionSort.h"
#include "Sorting/MergeSort.h"
#include "Sorting/HeapSort.h"
#include "Sorting/QuickSort.h"
#include "DS/BSTree/BSTree.h"
#include "DS/RBTree/RBTree.h"

using namespace std;

int main() {
//    int arr[10] = {4,1,3,2,16,9,10,14,8,7};
//    int arr[4] = {7,2,3,1};
//    int length = sizeof(arr)/sizeof(arr[0]);
//    printf("Before Sort\n");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ",arr[i]);
//    }
//    auto sort = new HeapSort();
//    sort->Sort(arr, length);
//    printf("\nAfter Sort\n");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ",arr[i]);
//    }
//    delete sort;

    // binary search tree
    RBTree* tree = new RBTree();
    int arr[11] = {15,6,3,7,2,4,13,9,18,17,20};
    int length = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < length; i++) {
        tree->insert(arr[i]);
    }
    auto min = tree->minimum(tree->getRoot());
    auto max = tree->maximum(tree->getRoot());
    printf("Min: %d\n",min->getValue());
    printf("Max: %d\n",max->getValue());
    auto result = tree->search(tree->getRoot(),9);
    if(result){
        printf("Found result: %d\n", result->getValue());
    }else{
        printf("The value %d wasn't found.\n", 9);
    }

    auto node = tree->search(tree->getRoot(),6);
    tree->deleteNode((RBNode*)node);

    result = tree->search(tree->getRoot(),6);
    if(result){
        printf("Found result: %d\n", result->getValue());
    }else{
        printf("The value %d wasn't found.\n", 6);
    }

    delete tree;
    // binary search tree





}