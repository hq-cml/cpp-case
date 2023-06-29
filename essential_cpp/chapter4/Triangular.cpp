//
// Created by hq on 2023/6/5.
//
#include <iostream>
#include <algorithm>
#include "Triangular.h"
using namespace std;

// Note: 类静态成员
//    1. _elems需要源文件中明确定义
//    2. _temp已经初始化，不需要在定义
//    3. static关键字仅需要在声明时候，这里不再需要
vector<int> Triangular::_elems;
//const int Triangular::_max_elem_cnt=1;


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
    //_elems = vector<int>(len);
}

// Note: 成员初始化列表
Triangular::Triangular(const Triangular &t):
_length(t._length), _next(t._next), _beg_pos(t._beg_pos){
    // Note：这里是空的，因为初始化工作已经由初始化列表完成！！！
}

// Note: 成员函数的const标记
//       1. 标记为const的成员函数定义在类外的话，也需要const标记
//       2. 这个标记可以参与重载判定！重载的第4种形式！！
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

int Triangular::GetBegin(string s) {
    cout << "the params: "<< s << endl;
    return _beg_pos;
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

// Note: 类静态成员函数
//      1. static关键字仅需要在声明时候，这里不再需要
void Triangular::gen_elems_to_value(int value) {
    int ix = _elems.size();
    if (!ix) {
        _elems.push_back(1);
        ix ++;
    }
    while(_elems[ix-1] < value && ix < _max_elem_cnt) {
        ix++;
        _elems.push_back(ix*(ix+1)/2);
    }
    if (ix >= _max_elem_cnt) {
        cerr << "too large"<<endl;
    }
}

void Triangular::gen_elems(int len) {
    if (len < 0 || len > _max_elem_cnt) {
        return;
    }

    if(_elems.size() < len) {
        int ix = _elems.size()?_elems.size()+1:1;
        for (; ix <= len; ix ++) {
            _elems.push_back(ix*(ix+1)/2);
        }
    }
    return;
}

// Note: 判断元素是否存在
//       这里使用了内置的泛型算法find()（第三章）
bool Triangular::has_elem(int val) {
    if (!_elems.size() || _elems[_elems.size()-1] < val){
        gen_elems_to_value(val);
    }

    vector<int>::iterator found = find(_elems.begin(), _elems.end(), val);
    return found != _elems.end();
}

void Triangular::display(ostream &os) {
    for(int i=0; i<_elems.size(); i++) {
        os << _elems[i] << ", ";
    }
    os<<endl;
}

void TestUseTrangular() {
    Triangular t;
    //t.Temp();

    //t.gen_elems_to_value(20);
    Triangular::gen_elems_to_value(20);

    // Note:: 静态函数
    //        可以使用类名调用，也可以使用成员实例调用
    Triangular::display();
    t.display();

    Triangular t2(5, 1);
    cout << "sum: " << sum(t2) <<endl;
    cout << "pos[1]: " << t2.elem(5) <<endl;

    cout << "has 5? "<< t2.has_elem(5) << endl;
    cout << "has 15? "<< Triangular::has_elem(15) << endl;

    // Note: 手动迭代器类Iterator Class的使用
    Triangular::iterator it = t2.begin();
    for (; it != t2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

// Note: 成员函数指针
//       1. 成员函数指针和普通函数指针的区别是比较大的
//       2. 首先是定义的时候，需要带类信息
//       3. 赋值的时候，采用&Class::func的形式赋值
//       4. 使用的时候，需要搭配一个对象来使用（因为真正的成员指针只有在对象中才会有）
//       5. 我个人理解之所以这么复杂的设计，是赋值的时候只用到了类信息，但是调用的时候却需要的是对象信息
void TestMemberFuncPtr() {
    Triangular t2(5, 1);
    Triangular *p1 = &t2;

    // 定义需要带类信息
    int (Triangular::*pm) (string) = 0;
    // 赋值需要&Class::func的形式赋值
    pm = &Triangular::GetBegin;
    // 使用需要搭配一个类对象
    cout << (t2.*pm)("hello") << endl;
    // 如果只有类对象的指针，则如下方法使用
    cout << (p1->*pm)("world") << endl;
}