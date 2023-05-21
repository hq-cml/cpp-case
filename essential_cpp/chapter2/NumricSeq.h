//
// Created by hq on 2023/5/21.
//

#ifndef CHAPTER2_NUMRICSEQ_H
#define CHAPTER2_NUMRICSEQ_H

#include <vector>
#include <iostream>
using namespace std;

// Note: 函数声明
//       1. 函数声明通常放在头文件，被其他程序include，提升可见性
// Note: 函数默认参数
//       1. 只能放在一个地方，要么声明中，要么定义中
//       2. 通常放在声明，而非定义中，这样可以使得引用方可见
void display(const vector<int> &, ostream & = cout);

void UseVector();

#endif //CHAPTER2_NUMRICSEQ_H
