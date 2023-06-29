//
// Created by hq on 2023/6/14.
//

#include "Triangular.h"
#include "NumSequence.h"
#include <iostream>
using namespace std;

// Note: 静态成员定义
vector<int> Triangular::_elems;

void Triangular::gen_elems(int pos) const {
    if (pos < 0) {
        return;
    }
    if(_elems.size() < pos) {
        int ix = _elems.size()?_elems.size()+1:1;
        for (; ix <= pos; ix ++) {
            _elems.push_back(ix*(ix+1)/2);
        }
    }
    return;
}

void TestUseTriangular() {
    Triangular tri(10);
    cout <<tri<<endl; // 触发print

    Triangular t2;
    cout << t2.elem(15) <<endl; // 触发check_integrity
}