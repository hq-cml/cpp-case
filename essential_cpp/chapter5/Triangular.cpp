//
// Created by hq on 2023/6/14.
//

#include "Triangular.h"
#include "NumSequence.h"
#include <iostream>
using namespace std;

// 静态成员定义
vector<int> Triangular::_elems;

int Triangular::elem(int pos) const {
    if(!check_integrity(pos, _elems.size())) {
        return 0;
    }
    return _elems[pos-1];
}

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

ostream& Triangular::print(ostream &os) const {
    int elem_pos = _beg_pos-1;
    int end_pos = elem_pos+_length;

    if (end_pos > _elems.size()) {
        Triangular::gen_elems(end_pos);
    }
    while(elem_pos < end_pos) {
        os << _elems[elem_pos++] << " ";
    }
    return os;
}

void TestUseTriangular() {
    Triangular tri(10);
    cout <<tri<<endl; // 触发print

    Triangular t2;
    cout << t2.elem(15) <<endl; // 触发check_integrity
}