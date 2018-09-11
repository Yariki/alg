//
// Created by Yariki on 9/2/2018.
//

#include "ShellSort.h"

//sample of my output for better understanding
//Before Sort
//4 1 3 2 16 9 10 14 8 7
//h = 5
//i=5
//4 1 3 2 16 9 10 14 8 7
//i=6
//4 1 3 2 16 9 10 14 8 7
//i=7
//4 1 3 2 16 9 10 14 8 7
//i=8
//4 1 3 2 16 9 10 14 8 7
//i=9
//j=9, j-h=4
//4 1 3 2 7 9 10 14 8 16
//
//h = 1
//i=1
//j=1, j-h=0
//1 4 3 2 7 9 10 14 8 16
//i=2
//j=2, j-h=1
//1 3 4 2 7 9 10 14 8 16
//i=3
//j=3, j-h=2
//j=2, j-h=1
//1 2 3 4 7 9 10 14 8 16
//i=4
//1 2 3 4 7 9 10 14 8 16
//i=5
//1 2 3 4 7 9 10 14 8 16
//i=6
//1 2 3 4 7 9 10 14 8 16
//i=7
//1 2 3 4 7 9 10 14 8 16
//i=8
//j=8, j-h=7
//j=7, j-h=6
//j=6, j-h=5
//1 2 3 4 7 8 9 10 14 16
//i=9
//1 2 3 4 7 8 9 10 14 16
//
//After Sort
//1 2 3 4 7 8 9 10 14 16


void ShellSort::Sort(int *arr, int length) {

    if(arr == nullptr){
        return;
    }
    auto N = length;
    auto h = 1;
    while(h < N/3) h = 3 + h + 1;

    while(h >= 1){
        printf("\nh = %d\n",h);
        for (int i = h; i < N; i++) {
            printf("i=%d\n",i);
            for (int j = i; j >= h && arr[j] < arr[j - h] ; j -= h) {
                printf("j=%d, j-h=%d\n",j,j-h);
                auto temp = arr[j-h];
                arr[j-h] = arr[j];
                arr[j] = temp;
            }
            printArray(arr,N); printf("\n");
        }
        h  = h/3;
    }

}

void ShellSort::printArray(int *a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ",a[i]);
    }
}


ShellSort::ShellSort() {}

ShellSort::~ShellSort() {

}
