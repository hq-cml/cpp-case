//
// Created by hq on 2023/6/5.
//
#include <iostream>
#include "Triangular.h"
using namespace std;
// 和默认值版本冲突
//Triangular::Triangular(){
//    _length = 1;
//    _beg_pos = 1;
//    _next = 0;
//}

Triangular::Triangular(int len){
    _length = len;
    _beg_pos = 1;
    _next = 0;
}

Triangular::Triangular(int len, int beg_pos) {
    _length = len;
    _beg_pos = beg_pos;
    _next = 0;
}

// Note: 成员初始化列表
Triangular::Triangular(const Triangular &t):
_length(t._length), _next(t._next), _beg_pos(t._beg_pos){
    // Note：这里是空的，因为初始化工作已经由初始化列表完成！！！
}

void TestUseTrangular() {
    Triangular t;
    cout << t.GetLen() <<endl;
}