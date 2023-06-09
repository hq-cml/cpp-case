//
// Created by hq on 2023/6/9.
//

#ifndef CHAPTER4_TRIANGULARITERATOR_H
#define CHAPTER4_TRIANGULARITERATOR_H

#include <iterator>
#include "Triangular.h"

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
//    if (_index >= Triangular::_max_elem_cnt) {
//        //throw iterator_overflow();
//    }
//
//    if (_index >= Triangular::_elems.size()) {
//        Triangular::
//    }
}


inline bool TriangularIterator::operator==(const TriangularIterator &t) const {
    return _index == t._index;
}
inline bool TriangularIterator::operator!=(const TriangularIterator &t) const {
    return  !(*this == t); // Note: 这里其实是调用了重载的==
}


#endif //CHAPTER4_TRIANGULARITERATOR_H
