//
// Created by hq on 2023/6/6.
//

#include "Matrix.h"

// Note：拷贝构造
//      1. 利用对象赋值来初始化，默认是“浅拷贝”，即每个成员变量逐个赋值
//      2. 如果成员里面有堆内存的指针，这将导致严重问题（二次释放堆内存）
//      3. 解决办法是实现拷贝构造函数，来单独处理堆内存
//      4. 拷贝构造还有个孪生兄弟拷贝赋值，通常她们应该成对出现
Matrix:: Matrix(const Matrix &m):_row(m._row), _col(m._col){
    _pmat = new double[_col * _row];
    // 堆内存拷贝
    for(int i=0; i<_col*_row; i++) {
        _pmat[i] = m._pmat[i];
    }
}

void TestUseMatrix() {
    Matrix m1(10, 10);
    // 如果没有实现拷贝构造函数，下面的语句将触发堆内存的二次释放，引发严重错误
    {
        Matrix m2 = m1;
    }
}
