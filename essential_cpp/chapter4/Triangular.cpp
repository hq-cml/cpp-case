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

vector<int> Triangular::_elems;

Triangular::Triangular(int len){
    _length = len;
    _beg_pos = 1;
    _next = 0;
}

Triangular::Triangular(int len, int beg_pos) {
    _length = len;
    _beg_pos = beg_pos;
    _next = 0;
    //_elems = vector<int>(len);
}

// Note: 成员初始化列表
Triangular::Triangular(const Triangular &t):
_length(t._length), _next(t._next), _beg_pos(t._beg_pos){
    // Note：这里是空的，因为初始化工作已经由初始化列表完成！！！
}

// Note: 成员函数的const标记
//       1. 标记为const的成员函数定义在类外的话，也需要const标记
//       2. 这个标记可以参与重载！重载的第4种形式！！
//       3. 一个const的引用变量，那么它只能调用被const标记过的方法！！！
//          反之，一个非const引用变量，可以调用所有的方法！！！
int Triangular::elem(int pos) const {
    return _elems[pos-1];
}

// Note: mutable关键字
//      1. next方法是const标记，所以它不应该修改类的成员
//      2. 但是此处_next，严格意义上来说不属于数列的基础属性
//      3. 所以使用mutable关键字使得它可以被const标记的方法修改
bool Triangular::next(int &v) const {
    if (_next<_beg_pos+_length-1) {
        v = _elems[_next++];
        return true;
    }
    return false;
}

// Note: this指针
Triangular& Triangular::copy(const Triangular &src) {
    if (this != &src) {
        this->_length = src._length; //Note: this->可省略
        _beg_pos = src._beg_pos;
        _next = src._next;
    }
    return *this;
}

// 数列求和
int sum(const Triangular &tria) {
    if (!tria.length()) {
        return 0;
    }
    int val, sum = 0;
    tria.next_reset();
    while(tria.next(val)) {
        sum += val;
    }
    return sum;
}

void TestUseTrangular() {
    Triangular t;
    //cout << sum(t) <<endl;
    //cout << t.elem(1) <<endl;
}