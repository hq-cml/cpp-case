//
// Created by hq on 2023/6/9.
//

#ifndef CHAPTER4_TRIANGULARITERATOR_H
#define CHAPTER4_TRIANGULARITERATOR_H

#include <iterator>
#include <iostream>
#include "Triangular.h"
using namespace std;
/*
 * Note: 实现自己的迭代器类
 * Note: 运算符重载
 */
class TriangularIterator {
public:
    TriangularIterator(int idx):_index(idx-1){} // 外部idx从1开始，内部从0开始
    //Note: 运算符重载
    bool operator==(const TriangularIterator &) const;
    bool operator!=(const TriangularIterator &) const;
    int operator*() const;
    TriangularIterator& operator++(); //Note: ++前置版本
    TriangularIterator operator++(int); //Note: ++后置版本
private:
    void check_integrity() const;
    int _index; // 整个类都是在维护这个index值，指向Triangular类对象_elems向量的元素
};

//Note: 内联函数定义在类外，需要额外指明inline
inline void TriangularIterator::check_integrity() const {
    if (_index >= Triangular::_max_elem_cnt) {
        //throw iterator_overflow();
        cerr <<"iterator_overflow" <<endl;
        return;
    }

    if (_index >= Triangular::_elems.size()) {
        Triangular::gen_elems(_index+1);
    }
}

inline bool TriangularIterator::operator==(const TriangularIterator &t) const {
    return _index == t._index;
}
inline bool TriangularIterator::operator!=(const TriangularIterator &t) const {
    return  !(*this == t); // Note: 这里其实是调用了重载的==
}
inline int TriangularIterator::operator*() const {
    check_integrity();
    return Triangular::_elems[_index];
}
inline TriangularIterator& TriangularIterator::operator++() { //Note: ++ 前置版本
    _index ++;
    check_integrity();
    return *this;
}
//Note: ++ 后置版本
//      1. 后置版本，固定写法是用一个int参数，这个参数无实际意义
//      2. 后置版本，返回的是一个临时变量，非引用，因为后置是先使用再自增
inline TriangularIterator TriangularIterator::operator++(int) {
    TriangularIterator it = *this; // 先拷贝一份自身
    _index ++;
    check_integrity();
    return *it;
}
#endif //CHAPTER4_TRIANGULARITERATOR_H
