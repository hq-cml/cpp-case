//
// Created by hq on 2023/6/5.
//

#ifndef CHAPTER4_STACK_H
#define CHAPTER4_STACK_H
#include <string>
#include <vector>
using namespace std;

void TestStack();

// Note: 类定义
//       1. 类定义放在头文件
class Stack {
public:
    // Note: 成员函数声明
    bool push(const string &);
    bool pop(string &elem);
    bool peak(string &elem);

    bool empty();
    bool full();

    // Note: 声明的同时直接给定义
    //       这种情况将成员函数自动变为内联函数
    int size() {return _stack.size();}

private:
    vector<string> _stack; // 成员变量下划线开头
};

// Note: 内联成员函数定义
//      1. 不在类内部定义的函数，需要inline关键字表示此函数是内联
//      2. 和普通函数一样，内联函数需要放在头文件
inline bool Stack::empty() {
    return _stack.empty();
}

inline bool Stack::full() {
    return _stack.size() == _stack.max_size();
}

#endif //CHAPTER4_STACK_H
