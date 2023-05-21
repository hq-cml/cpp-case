#include <iostream>
using namespace std;
#include "NumricSeq.h"

// Note: 函数的声明，让编译器知道begin函数的存在。
void begin();

int main() {
    UseVector();

    //begin();
    return 0;
}

// 斐波那契数列: 0, 1, 1, 2, 3( pos从0开始计数）
// Note: 利用引用参数作为返回值，关于引用：
//      1. 本质上引用是指针的另一种使用形式，但也存在一点区别
//      2. 指针可以为空，也可以变更指向；引用不能为空引用，且从一而终，不能变更
//      3. 将引用作为函数的入参，本质上复制的是对象的地址
//      4. 引用作为参数的另一个好处是，避免了内存的大量拷贝
bool fibon_elem(int pos, int &elem) {
    if (pos <=0 || pos > 1024) {
        elem = 0;
        return false;
    }
    elem = 1;
    int n1 = 1, n2 = 1;
    for (int idx = 3; idx <= pos; idx ++) {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
    }
    return true;
}

void begin() {
    int pos;
    cout << "Please input a pos:";
    cin >> pos;

    int elem;
    if(fibon_elem(pos, elem)) {
        cout << "Elem #" << pos << " is " << elem <<endl;
    } else {
        cout << "Sorry. Invalid pos:"<<pos<<endl;
    }
}

