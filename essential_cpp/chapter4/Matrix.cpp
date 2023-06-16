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
    cout << "copy construct" << endl;
    _pmat = new double[_col * _row];
    // 堆内存拷贝
    for(int i=0; i<_col*_row; i++) {
        _pmat[i] = m._pmat[i];
    }
}

// Note：拷贝赋值
//     1. 和拷贝构造针对的都是“深拷贝”的问题
//     2. 区别在于使用场景不同，拷贝赋值应用于赋值场景
Matrix& Matrix::operator=(const Matrix &src) {
    cout << "copy assignment" << endl;
    if (this == &src) {
        return *this;
    }
    _row = src._row;
    _col = src._col;
    delete [] _pmat;
    _pmat = new double[_col * _row];
    // 堆内存拷贝
    for(int i=0; i<_col*_row; i++) {
        _pmat[i] = src._pmat[i];
    }
    return *this;
}

// Note: 重载<<和>>
//       1. 注意，这里是运算符重载的第二种形式！--非成员函数
//       2. 之所以采用非成员函数形式，因为成员函数要求参数1是类对象本身
//       3. 这里涉及到参数顺序的问题，类对象需要作为第二个参数，所以采用了非成员函数方式
//       4. 重载<<，类似与Java的ToString；重载>>毫无意义得复杂，这里省略了
ostream& operator<<(ostream &os, const Matrix &src) {
    os << "row: " << src._row << ". col: "<< src._col << endl;
    return os;
}

void TestUseMatrix() {
    Matrix m1(10, 10);
    // 如果没有实现拷贝构造函数，下面的语句将触发堆内存的二次释放，引发严重错误
    {
        Matrix m2 = m1;
    }

    Matrix m3(1, 1);
    m3 = m1;

    cout << m1;
}
