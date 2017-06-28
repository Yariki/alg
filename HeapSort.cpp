//
// Created by Yariki on 5/24/2017.
//

#include <array>
#include "HeapSort.h"

using namespace std;

void HeapSort::Sort(int *arr, int length)
{
    int heapSize = length - 1;
    buildMaxHeap(arr,length, heapSize);
    for (int i = heapSize; i > 0 ; i--)
    {
        swap(arr[0],arr[i]);
        heapSize--;
        maxHeapify(arr,0,heapSize);
    }
}

int HeapSort::getParent(int currentIndex)
{
    return currentIndex / 2;
}

int HeapSort::getLeft(int currentIndex)
{
    return 2 * currentIndex ;
}

int HeapSort::getRight(int currentIndex)
{
    return 2* currentIndex + 1;
}

void HeapSort::maxHeapify(int *arr, int currentIndex, int heapSize)
{
    int largest = currentIndex;
    int leftIndex = getLeft(currentIndex);
    int rightIndex = getRight(currentIndex);

    if(leftIndex <= heapSize && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }
    if(rightIndex <= heapSize && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }
    if(largest != currentIndex){
        swap(arr[currentIndex],arr[largest]);
        maxHeapify(arr,largest,heapSize);
    }
}

void HeapSort::buildMaxHeap(int *arr, int lenght, int heapSize)
{
    int middle = heapSize / 2 ;
    for (int i = middle; i >= 0; i--)
    {
        maxHeapify(arr,i,heapSize);
    }
}


