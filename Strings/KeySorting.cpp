

#include "KeySorting.h"


void keySorting(char *arr, int size){

    const  int N = size;
    const int R = 256;
    
    int aux[N];
    int count[R + 1];

    memset(aux,0, sizeof(int) * N);
    memset(count,0, sizeof(int) * (R + 1));


    for (int i = 0; i < N; i++){
        count[arr[i] + 1]++;
    }
    for(int r = 0; r < R; r++){
        count[r+1] += count[r];
    }
    for (int i = 0; i < N; i++)
    {
        aux[count[arr[i]]++] = arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        arr[i] = aux[i];
    }
}

