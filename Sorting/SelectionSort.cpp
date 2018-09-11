//
// Created by Yariki on 9/2/2018.
//

#include "SelectionSort.h"

void SelectionSort::Sort(int *arr, int length) {
    std::array<int, 10> ar = {2,4,6,8,3,1,3,2,9,7};

    for (int i = 0; i < ar.size(); ++i) {
        auto min = i;
        for (int j = i+1; j < ar.size(); ++j) {
            if(ar[j] < ar[min]){
                min = j;
            }
        }
        auto temp = ar[min];
        ar[min] = ar[i];
        ar[i] = temp;
    }

    for (int k = 0; k < ar.size(); ++k) {
        printf("%d ",ar[k]);
    }

}

SelectionSort::SelectionSort() {}

SelectionSort::~SelectionSort() {

}
