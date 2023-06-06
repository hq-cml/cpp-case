//
// Created by hq on 2023/6/6.
//

#ifndef CHAPTER4_MATRIX_H
#define CHAPTER4_MATRIX_H

#include <iostream>
using namespace std;

void TestUseMatrix();

// Note: 析构函数
class Matrix {
public:
    Matrix(int row, int col):_col(col),_row(row) {
        // 分配堆内存
        _pmat = new double[_col * _row];
    }
    // Note：拷贝构造
    Matrix(const Matrix &);
    ~Matrix() {
        // 通过析构函数自动释放堆内存
        cout << "release"<<endl;
        delete []_pmat;
    }
private:
    int _row, _col;
    double *_pmat;
};

#endif //CHAPTER4_MATRIX_H
