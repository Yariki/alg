#include <iostream>
#include "Sorting/InsertionSort.h"
#include "Sorting/MergeSort.h"
#include "Sorting/HeapSort.h"
#include "Sorting/QuickSort.h"
#include "DS/BSTree/BSTree.h"
#include "DS/RBTree/RBTree.h"
#include "Sorting/SelectionSort.h"
#include "Sorting/ShellSort.h"
#include "Sorting/Quick3WaySort.h"
#include "DS/PriorityQueue/PriorityQueue.h"

using namespace std;

int main() {
    //int arr[10] = {4,1,3,2,16,9,10,14,8,7};
//    int arr[5] = {1,3,1,-1,3};
    //int length = sizeof(arr)/sizeof(arr[0]);
//    printf("Before Sort\n");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ",arr[i]);
//    }
//    auto sort = new Quick3WaySort();
//    sort->Sort(arr, length);
//    printf("\nAfter Sort\n");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ",arr[i]);
//    }
//    delete sort;


//    auto pq = new PriorityQueue(10);
//    for (int j = 0; j < length; ++j) {
//        pq->insert(arr[j]);
//    }
//
//    while(!pq->isEmpty()){
//        auto max = pq->getMax();
//        printf("%d ",max);
//    }
//
//    delete pq;

    // binary search tree
    RBTree* tree = new RBTree();
    int arr[6] = {1,2,3,4,5,6};
    int length = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < length; i++) {
        tree->insert(arr[i]);
    }
    //tree->display();
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

    auto node = tree->search(tree->getRoot(),4);
    tree->deleteNode((RBNode*)node);

    result = tree->search(tree->getRoot(),4);
    if(result){
        printf("Found result: %d\n", result->getValue());
    }else{
        printf("The value %d wasn't found.\n", 6);
    }

    delete tree;
    // binary search tree

//    auto selectionSort = new SelectionSort();
//
//    selectionSort->Sort(nullptr,0);
//
//    delete selectionSort;


}