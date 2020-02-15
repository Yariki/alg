//
// Created by Yariki on 2/15/2020.
//

#ifndef ALGORITHMS_LSD_H
#define ALGORITHMS_LSD_H

#include <string>
#include <vector>

using std::string;
using std::vector;


class LSD {
private:
    vector<string> strings;

    void init(string filename);

public:
    LSD(string filename);
    virtual ~LSD();
    vector<string> sort();

};


#endif //ALGORITHMS_LSD_H
