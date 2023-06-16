#include <iostream>

#include "LibMat.h"
#include "Fibonacci.h"
#include "Triangular.h"
#include "Matrix.h"

void TestInherit();
void TestDestructor();

int main() {
    UseMatrix();
    //TestInherit();
    //TestUseTriangular();
    // TestUseFib();
    //TestPrint();
    //TestDestructor();
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

// Note：最简单的继承关系
class B {
public:
    //Note: 构造函数是否是默认
    //      1. 一个完全没有参数的构造函数，算是默认构造函数
    //      2. 如果有参数的默认值，使得调用看起来没有参数，也算是默认构造函数
    //      3. 比如本类就没有默认构造，因为提供了一个单参数的构造函数，同时还没有不带参数的构造
    B(int v):_v(v) {
        cout<< "B construct"<<endl;
    }
    ~B() {
        cout << "B relase" <<endl;
    }
private:
    int _v;
};

class C:public B {
public:
    //Note: 基类没有默认构造函数
    //      1.子类必须要手动调用基类构造，否则编译报错！
    //      2.调用的方法是使用初始化器，如下
    C():B(1) {
        cout<< "C construct"<<endl;
    }
    //Note：析构函数
    //      1. 基类析构是自动调用的！！不需要做什么
    ~C() {
        cout << "C release"<< endl;
    }
};

void TestDestructor() {
    {
        C c;
    }
    cout << "End";
}