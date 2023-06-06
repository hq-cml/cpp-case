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

void TestUseTrangular() {
    Triangular t;
    cout << t.GetLen() <<endl;
}