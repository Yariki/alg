#ifndef __MSD_H__
#define __MSD_H__

#include <vector>
#include <string>

using std::string;
using std::vector;

class MSD
{
private:
    vector<string> strings;
    vector<string> aux;

    void init(string filename);
    int charAt(string &str, int d);
    void sort(vector<string> &arr, int lo, int hi, int d);
    void insertionSort(vector<string> &arr, int lo, int hi, int d);
    bool less(string &v, string &w, int d);

public:
    MSD(string filename);
    virtual ~MSD();
    vector<string> sort();

};





#endif // __MSD_H__