//
// Created by hq on 2023/6/11.
//

#ifndef CHAPTER5_FIBONACCI_H
#define CHAPTER5_FIBONACCI_H

#include "NumSequence.h"
#include <iostream>
#include <vector>
using namespace std;

void TestUseFib();

// Note: public 继承NumSequence
//      1. 父类中的public成员和protected成员可以无缝使用
//      2. 父类中的private成员不能使用
class Fibonacci: public NumSequence {
public:
    Fibonacci(int len=1, int beg_pos=1):
    _length(len), _beg_pos(beg_pos){}

    virtual int elem(int pos) const;                          // 返回pos位置的元素
    virtual const char * what_am_i() const {return "Fibonacci";}   //返回确切的数列类型
    virtual ostream &print(ostream &os=cout) const;           // 输出所有元素

    int length()const {return _length;}
    int beg_pos() const {return _beg_pos;}
protected:
    virtual void gen_elems(int pos) const;
    int _length;
    int _beg_pos;
    static vector <int> _elems;
};

#endif //CHAPTER5_FIBONACCI_H
