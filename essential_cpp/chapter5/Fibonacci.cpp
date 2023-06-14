//
// Created by hq on 2023/6/11.
//

#include "Fibonacci.h"
#include "NumSequence.h"
#include <iostream>
using namespace std;

// Note: 类静态成员_elems需要源文件中明确定义
vector <int> Fibonacci::_elems;

void Fibonacci::gen_elems(int pos) const {
    //cout << "gen_elems" << endl;
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

void TestUseFib() {
    Fibonacci fib(10);
    cout <<fib<<endl; // 触发print

    Fibonacci fib2;
    cout << fib2.elem(15) <<endl; // 触发check_integrity
}