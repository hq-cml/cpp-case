//
// Created by hq on 2023/6/11.
//

#include "LibMat.h"
void print(const LibMat& mat);

void TestPrint() {
    LibMat libmat;
    print(libmat);
    cout << "------------------------------------"<< endl;

    Book b("foo", "bar");
    print(b);
    cout << "------------------------------------"<< endl;

    AudioBook a("foo", "bar", "shit");
    print(a);
    cout << "------------------------------------"<< endl;
}

void print(const LibMat& mat) {
    mat.print();

}

// TODO 补充一个例子
// Note: 这里用了一个域作用符
//      1. 作者解释这样做是为了直接指定调用Fibonacci类的gen_elems，而不是调用父类的，强行掩盖虚拟机制
//      2. 根据实际测试，这里加不加这个域作用符效果相同，而且根据覆盖原则，可以解释得通
//      3. 子类和父类出现同名成员，则默认情况下子类对成员的使用，必然是子类的成员（除非强行使用父类域作用符）