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

// Note: <<运算符重载
ostream &operator<<(ostream &os, const NumSequence &ns) {
    return ns.print(os);
}