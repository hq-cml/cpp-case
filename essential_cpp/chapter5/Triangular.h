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
    _length(len), _beg_pos(beg_pos){}

    virtual int elem(int pos) const;
    virtual const char* what_am_i() const {return "Triangular";}
    virtual ostream& print(ostream& os=cout) const;

    int length() const {return _length;}
    int beg_pos() const {return _beg_pos;}

protected:
    virtual void gen_elems(int pos) const;
    int _length;
    int _beg_pos;
    static vector<int> _elems;
};

#endif //CHAPTER5_TRIANGULAR_H
