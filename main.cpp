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
#include "DS/RBTree/LLRBTree.h"
#include "DS/Hashset/SeparateChainingHashSet.h"
#include "DS/Graph/Undirect/UndirectGraph.h"
#include "DS/Graph/BreadthSearch.h"
#include "DS/Graph/DepthSearch.h"
#include "DS/Graph/ConnectedComponent.h"
#include "DS/Graph/Direct/Digraph.h"
#include "DS/Graph/TopologicalSort.h"

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
//    LLRBTree* tree = new LLRBTree();
//    int arr[7] = {10,2,3,25,6,17,30};
//    int length = sizeof(arr)/sizeof(arr[0]);
//    for (int i = 0; i < length; i++) {
//        tree->insert(arr[i]);
//    }
//    //tree->display();
//    auto min = tree->minimum(tree->getRoot());
//    auto max = tree->maximum(tree->getRoot());
//    printf("Min: %d\n",min->getValue());
//    printf("Max: %d\n",max->getValue());
//    auto result = tree->search(tree->getRoot(),9);
//    if(result){
//        printf("Found result: %d\n", result->getValue());
//    }else{
//        printf("The value %d wasn't found.\n", 9);
//    }
//
//    result = tree->search(tree->getRoot(),4);
//    if(result){
//        printf("Found result: %d\n", result->getValue());
//    }else{
//        printf("The value %d wasn't found.\n", 6);
//    }
//
//    delete tree;
    // binary search tree

//    auto selectionSort = new SelectionSort();
//
//    selectionSort->Sort(nullptr,0);
//
//    delete selectionSort;

//    std::string sample = "sampleexample";

//    SeparateChainingHashSet *hashSet = new SeparateChainingHashSet(sample.length());
//
//    for (int i = 0; i < sample.length(); ++i) {
//        char ch = sample[i];
//        hashSet->put(ch,i);
//    }
//    hashSet->print();
//    delete hashSet;
//    hashSet = nullptr;

    // undirect graph
//    auto graph1 = new UndirectGraph();
//    graph1->init("tinyG2.txt");
//    auto breadthSearch = new BreadthSearch(graph1,0);

//    auto graph2 = new UndirectGraph();
//    graph2->init("tinyG.txt");
//    auto depth = new DepthSearch(graph2);
//    auto cc = new ConnectedComponent(graph2);

    // direct graph
    auto graph1 = new Digraph();
    graph1->init("tinyDG2.txt");
    auto breadthSearch = new BreadthSearch(graph1,0);

    auto graph2 = new Digraph();
    graph2->init("tinyDG.txt");
    auto depth = new DepthSearch(graph2);
    auto cc = new ConnectedComponent(graph2);

    auto graph3 = new Digraph();
    graph3->init("tinyDG3.txt");
    auto top = new TopologicalSort(graph3);

    delete breadthSearch;
    delete depth;
    delete cc;
    delete top;
    delete graph1;
    delete graph2;
    delete graph3;
}