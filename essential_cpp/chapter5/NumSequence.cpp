//
// Created by hq on 2023/6/11.
//

#include "NumSequence.h"
#include <iostream>
using namespace std;

bool NumSequence::check_integrity(int pos, int size) const {
    if (pos <=0 || pos > _max_elems) {
        cerr << "invalid pos" << endl;
        return false;
    }

    // Note: 这里非常骚的操作
    //     1. 在父类中调用了一个纯虚函数
    //     2. 这里最终将因为多态机制，实际调用的是子类的方法！
    if(pos > size) {
        //cout << "here2" <<endl;
        gen_elems(pos);
    }
    return true;
}


int NumSequence::elem(int pos) const {
    // Note: 无缝使用继承得来的函数
    if(!check_integrity(pos, _relems.size())) {
        return 0;
    }
    return _relems[pos-1];
}


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