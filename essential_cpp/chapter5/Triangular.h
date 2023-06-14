//
// Created by hq on 2023/6/14.
//

#ifndef CHAPTER5_TRIANGULAR_H
#define CHAPTER5_TRIANGULAR_H

#include "NumSequence.h"
#include <iostream>
#include <vector>
using namespace std;

void TestUseTriangular();

// 和Fibonacci同等地位
class Triangular: public NumSequence {
public:
    Triangular(int len=1, int beg_pos=1):
        NumSequence(len, beg_pos, _elems){}

    virtual const char* what_am_i() const {return "Triangular";}

protected:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};

#endif //CHAPTER5_TRIANGULAR_H
