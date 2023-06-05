//
// Created by hq on 2023/6/5.
//
#include <iostream>
#include "Stack.h"
using namespace std;

// Note: 成员函数定义
//       1. 普通的成员函数定义，放在源文件中
bool Stack::pop(string &elem) {
    if (empty()){
        return false;
    }

    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peak(string &elem) {
    if (empty()){
        return false;
    }

    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem) {
    if (full()){
        return false;
    }

    _stack.push_back(elem);
    return true;
}

void TestStack() {
    Stack s;
    string str;
    while(cin >> str && !s.full()) { // ctrl+d结束
        s.push(str);
    }

    while(!s.empty()) {
        s.pop(str);
        cout << "pop: "<< str << endl;
    }
}