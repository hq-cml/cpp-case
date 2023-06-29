//
// Created by hq on 2023/6/16.
//
#include "Matrix.h"

// 拷贝构造
Matrix::Matrix(const Matrix&src):cap(src.cap) {
    cout << "Father Copy Constructor" << endl;
    p = new int[cap];
    for (int i=0; i<cap; i++) {
        p[i]= src.p[i];
    }
}

// 拷贝赋值
Matrix& Matrix::operator=(const Matrix &src) {
    cout << "Father Copy =" << endl;
    delete []p;
    cap = src.cap;
    p = new int[cap];
    for (int i=0; i<cap; i++) {
        p[i]= src.p[i];
    }
    return *this;
}

// Note: 子类拷贝构造
//       1. 实际上测试了一下，如果子类不提供拷贝构造，父类的拷贝构造仍然会自动调用
//       2. 但是，如果像这里如果子类实提供了拷贝构造，则必须在初始化器调用父类的拷贝构造
//       3. 如果父类没有提供拷贝构造，编译器会调用默认的（但是，如果此时父类有堆内存，就会导致二次释放）
Sub::Sub(const Sub&src): Matrix(src) {
    cout << "Son Copy Constructor[" << name <<"]"<< endl;
}

// Note: 子类拷贝赋值
//       1. 和拷贝构造同理，如果子类不提供拷贝赋值，父类的拷贝赋值仍然会自动调用
//       2. 但是，如果像这里如果有拷贝赋值，则必须手动调用父类的拷贝赋值
//       3. 如果父类没有提供拷贝构造，编译器会调用默认的（但是，如果此时父类有堆内存，会导致异常，内存非法访问）
Sub& Sub::operator=(const Sub& src){
    cout << "Son Copy =[" << name <<"]"<< endl;
    // Note：手动调用父类的拷贝赋值，通过类作用域符调用，必须！
    if (this != &src) {
        Matrix::operator=(src);
    }
    this->name = src.name;
    return *this;
}

void UseMatrix() {
//    Matrix m1(10);
//    {
//        Matrix m2 = m1;
//    }
//    Sub s1(10, "foo");
//    {
//        Sub s2 = s1;
//    }
    Sub s1(10, "foo");
    {
        Sub s2(5, "bar");
        s2 = s1;
        cout << "s2.get(5)="<<s2.Get(5)<<endl; // 如果拷贝赋值实现的不正确，这里就会越界
        cout << "s2.cap="<<s2.Cap()<<endl;
    }
}