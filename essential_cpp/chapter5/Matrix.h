//
// Created by hq on 2023/6/16.
//

#ifndef CHAPTER5_MATRIX_H
#define CHAPTER5_MATRIX_H
#include <iostream>
using namespace std;

void UseMatrix();
/*
 * Note: 测试基类存在深拷贝的场景
 *       基类有成员变量，并且还是指向堆内存的指针
 *       此时，基类需要提供拷贝构造和拷贝赋值
 *       其子类的处理则需要格外注意！
 *       结论：最好别在基类这么设计。。。
 */
class Matrix {
public:
    // 构造
    Matrix(int c):cap(c) {
        cout << "Father Constructor" << endl;
        p = new int[c];
    }
    // 析构
    ~Matrix() {
        cout << "Father Release" << endl;
        delete []p;
    }
    // 拷贝构造
    Matrix(const Matrix&);
    // 拷贝赋值
    Matrix& operator=(const Matrix&);

    int Cap() {return cap;}
    int Get(int idx) {return p[idx];}
private:
    int cap;
    int *p;
};

// 子类
class Sub: public Matrix {
public:
    Sub(int c, string name): Matrix(c) {
        cout << "Son Constructor[" << name <<"]"<< endl;
        this->name = name;
    }
    ~Sub() {
        cout << "Son Release[" << name <<"]"<< endl;
    }

    // 拷贝构造
    Sub(const Sub&);

    // 拷贝赋值
    Sub& operator=(const Sub&);
private:
    string name;
};

#endif //CHAPTER5_MATRIX_H
