//
// Created by hq on 2023/6/11.
//

#include "Fibonacci.h"
#include <iostream>
using namespace std;

// Note: 类静态成员_elems需要源文件中明确定义
vector <int> Fibonacci::_elems;

int Fibonacci::elem(int pos) const {
    // Note: 无缝使用继承得来的函数
    if(!check_integrity(pos, _elems.size())) {
        return 0;
    }
    return _elems[pos-1];
}

void Fibonacci::gen_elems(int pos) const {
    cout << "gen_elems" << endl;
    if (_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }
    if (_elems.size() <= pos ){
        int ix = _elems.size();
        int n2 = _elems[ix-2];
        int n1 = _elems[ix-1];
        for (; ix <= pos; ix ++) {
            int tmp = n1+n2;
            _elems.push_back(tmp);
            n2=n1; n1=tmp;
        }
    }
}

ostream &Fibonacci::print(ostream &os) const {
    int elem_pos = _beg_pos-1;
    int end_pos = elem_pos+_length;

    if (end_pos > _elems.size()) {
        cout << "here1" <<endl;
        // Note: 这里用了一个域作用符
        //      1. 作者解释这样做是为了直接指定调用Fibonacci类的gen_elems，而不是调用父类的，强行掩盖虚拟机制
        //      2. 根据实际测试，这里加不加这个域作用符效果相同，而且根据覆盖原则，可以解释得通
        //      3. 子类和父类出现同名成员，则默认情况下子类对成员的使用，必然是子类的成员（除非强行使用父类域作用符）
        Fibonacci::gen_elems(end_pos);
    }
    while(elem_pos < end_pos) {
        os << _elems[elem_pos++] << " ";
    }
    return os;
}

// Note: <<运算符重载
ostream &operator<<(ostream &os, const NumSequence &ns) {
    return ns.print(os);
}

void TestUseFib() {
    Fibonacci fib(10);
    cout <<fib<<endl; // 触发print

    Fibonacci fib2;
    cout << fib2.elem(15) <<endl; // 触发check_integrity
}