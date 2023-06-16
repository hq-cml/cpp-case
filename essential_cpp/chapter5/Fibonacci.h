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
    // Note: 子类构造函数需要先调用父类构造函数
    //       1. 原因是因为父类有成员变量，所以提供了基类构造函数，需要调用以初始化
    //       2. 调用基类构造的方式是通过子类构造函数初始化器调用父类构造函数
    //       3. 如果想避免这样，只能为基类提供默认构造（无参数），这样编译器会自动调用基类默认构造
    Fibonacci(int len=1, int beg_pos=1):
            NumSequence(len, beg_pos, _elems){}

    virtual const char * what_am_i() const {return "Fibonacci";}   //返回确切的数列类型

protected:
    virtual void gen_elems(int pos) const;
    static vector <int> _elems;
};

#endif //CHAPTER5_FIBONACCI_H
