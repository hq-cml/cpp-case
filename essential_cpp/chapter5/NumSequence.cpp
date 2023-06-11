//
// Created by hq on 2023/6/11.
//

#include "NumSequence.h"
#include <iostream>
using namespace std;

bool NumSequence::check_integrity(int pos) {
    if (pos <=0 || pos > _max_elems) {
        cerr << "invalid pos" << endl;
        return false;
    }
    return true;
}

// Note: <<运算符重载
ostream &operator<<(ostream &os, const NumSequence &ns) {
    return ns.print(os);
}