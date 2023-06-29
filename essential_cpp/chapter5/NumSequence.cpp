//
// Created by hq on 2023/6/11.
//
#include "NumSequence.h"
#include <iostream>
using namespace std;

// 检查pos是否为有效位置，并且如果此时序列没有达到pos，则自动延展
bool NumSequence::check_integrity(int pos, int size) const {
    if (pos <=0 || pos > _max_elems) {
        cerr << "invalid pos" << endl;
        return false;
    }

    // Note: 这里非常骚的操作
    //     1. 在父类中调用了一个纯虚函数
    //     2. 这里最终将因为多态机制，实际调用的是子类的方法！
    //     3. 注意这种骚操作有一个例外！
    //        如果是在构造函数、析构函数内，多态机制失效，只会调用父类自己的函数
    //        原因是因为调用父类构造的时候，子类对象还未生成或已经消失
    if(pos > size) {
        //cout << "here2" <<endl;
        gen_elems(pos); // Note：本质上是指针引发多态，等价于this->gen_elems(pos);
    }
    return true;
}

// 返回pos位置的元素
int NumSequence::elem(int pos) const {
    if(!check_integrity(pos, _relems.size())) {
        return 0;
    }
    return _relems[pos-1];
}

// 输出所有元素
ostream& NumSequence::print(ostream &os) const {
    int elem_pos = _beg_pos-1;
    int end_pos = elem_pos+_length;

    if (end_pos > _relems.size()) {
        //cout << "here1" <<endl;
        gen_elems(end_pos);
    }
    while(elem_pos < end_pos) {
        os << _relems[elem_pos++] << " ";
    }
    return os;
}

// Note: <<运算符重载
ostream &operator<<(ostream &os, const NumSequence &ns) {
    return ns.print(os);
}