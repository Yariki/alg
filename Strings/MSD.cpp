#include "MSD.h"
#include <fstream>
#include <iostream>
#include <memory.h>

const int R = 256;
const int M = 15;

MSD::MSD(string filename)
{
    init(filename);
}

MSD::~MSD()
{
}
void MSD::init(string filename)
{
    std::ifstream file(filename);
    if(file.good() && file.is_open()){
        string line;
        std::getline(file, line);
        strings.push_back(line);

        while(!file.eof()){
            std::getline(file,line);
            strings.push_back(line);
        }
        file.close();
    }
}

vector<string> MSD::sort()
{
    auto N = strings.size();
    aux = vector<string>(N);
    sort(strings,0, N -1, 0);
    return strings;
}

int MSD::charAt(string &str, int d)
{
    return d < str.size() ? str[d] : -1;
}

void MSD::sort(vector<string> &arr, int lo, int hi, int d)
{
    if(hi <= lo + M)
    {
        insertionSort(arr,lo,hi,d);
        return;
    }
    int count[R + 2];
    for (int i = lo; i < hi; i++)
    {
        count[charAt(arr[i],d) + 2]++;
    }
    for (int r = 0; r < R + 1; r++)
    {
        count[r+1] += count[r];
    }

    for (int i = lo; i <= hi; i++)
    {
        aux[count[charAt(arr[i],d) + 1]++] = arr[i];
    }
    
    for (int i = lo; i <= hi; i++)
    {
        arr[i] = aux[i - lo];
    }

    for (int r = 0; r < R; r++)
    {
        sort(arr,lo + count[r], lo + count[r+1] - 1, d+1);        
    }
}

void MSD::insertionSort(vector<string> &arr, int lo, int hi, int d)
{
        for (int i = lo; i <= hi; i++)
        {
            for (int j = i; j > lo && less(arr[j], arr[j-1],d); j--)
            {
                auto temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
}

bool MSD::less(string &v, string &w, int d)
{
    return v.substr(d).compare(w.substr(d)) < 0;
}
