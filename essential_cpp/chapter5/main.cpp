#include <iostream>

#include "LibMat.h"
#include "Fibonacci.h"
#include "Triangular.h"

void TestInherit();

int main() {
    TestInherit();
    //TestUseTriangular();
    // TestUseFib();
    //TestPrint();
    return 0;
}

void Display(ostream& os, const NumSequence& ns, int pos) {
    os << "The elem at pos[" << pos << "] for the " <<
    ns.what_am_i() << " sequence is " << ns.elem(pos) << endl;
    return;
}

// 测试继承和多态
void TestInherit() {
    const int pos =8;
    Fibonacci fib;
    Display(cout, fib, pos);

    Triangular tr;
    Display(cout, tr, pos);

    Fibonacci fib2(8,1);
    cout << "Fib: " << fib2 << endl;
    Triangular tr2(8,1);
    cout << "Tri: " << tr2 << endl;
}