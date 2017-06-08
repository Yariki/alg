//
// Created by Yariki on 5/24/2017.
//

#include <array>
#include "HeapSort.h"

using namespace std;

void HeapSort::Sort(int *arr, int length)
{
    int heapSize = length;
    buildMaxHeap(arr,length);
    for (int i = (length - 1); i > 0 ; i--)
    {
        swap(arr[0],arr[i]);
        heapSize--;
        maxHeapify(arr,0,i);
    }
}

int HeapSort::getParent(int currentIndex)
{
    return currentIndex / 2;
}

int HeapSort::getLeft(int currentIndex)
{
    return 2 * currentIndex + 1;
}

int HeapSort::getRight(int currentIndex)
{
    return 2* currentIndex + 2;
}

void HeapSort::maxHeapify(int *arr, int currentIndex, int heapSize)
{
    int largest = currentIndex;
    int leftIndex = getLeft(currentIndex);
    int rightIndex = getRight(currentIndex);

    if(leftIndex <= heapSize && arr[leftIndex] > arr[currentIndex])
    {
        largest = leftIndex;
    }
//    else
//        largest = currentIndex;
    if(rightIndex <= heapSize && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }
    if(largest != currentIndex){
        swap(arr[currentIndex],arr[largest]);
        maxHeapify(arr,largest,heapSize);
    }
}

void HeapSort::buildMaxHeap(int *arr, int lenght)
{
    int heapSize = lenght;
    int middle = lenght / 2 - 1;
    for (int i = middle; i >= 0; i--)
    {
        maxHeapify(arr,i,heapSize);
    }
}


