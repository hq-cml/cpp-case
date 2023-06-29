//
// Created by hq on 2023/6/5.
//

#ifndef CHAPTER4_TRIANGULAR_H
#define CHAPTER4_TRIANGULAR_H
#include <vector>
using namespace std;

void TestUseTrangular();
void TestMemberFuncPtr();

//Note: TriangularIterator类
//     1. 手动实现的迭代器类
//     2. 运算符重载
//     3. 通常最好是单独定义一套.cpp和.h，但是这个类比较特殊，存在循环include头文件的问题
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


// Note: 主类
class Triangular {
public:
    // Note: 友元类
    //      1. 将TriangularIterator声明为主类的朋友类，则在迭代器里面可以访问主类的private成员
    //      2. 友元的另一种形式是友元函数，就是只针对一个方法来声明友元，同样是使用friend关键字
    //      3. 友元破坏了封装性，最好别乱用，这里其实可以对private成员提供public的getter方法避免友元
    friend class TriangularIterator;

    // Note: 构造函数
    //       1. 支持重载
    //       2. 可以有默认值，在声明中声明即可
    //       3. 可以使用成员初始化列表
    //Triangular(); // 默认的构造函数，会和默认值版本冲突
    Triangular(int len);
    Triangular(int len=1, int beg_pos=1); // 默认值
    Triangular(const Triangular &);
    int GetLen() {return _length;}

    // Note: 成员函数的const标记
    //       1. 被标记为const的成员函数，不能够修改成员值
    //       2. 标记为const的成员函数定义在类外的话，也需要const标记
    int length() const {return _length;}
    int beg_pos() const {return _beg_pos;}
    int elem(int pos) const;
    bool next(int &v) const;
    void next_reset() const {_next = _beg_pos - 1;}

    // 非const标记成员函数
    Triangular& copy(const Triangular& src);
    int GetBegin(string s); // 测试成员函数指针

    // Note: 类静态成员函数
    static void gen_elems_to_value(int value);
    static void gen_elems(int len);
    static void display(ostream &os = cout);
    static bool has_elem(int val);

    // Note: 将手动实现的Iterator Class内嵌到主类中
    //       通过typedef，使得iterator成为一种类型（内嵌类型）
    //       外部可以使用Triangular::iterator来定义迭代器变量了
    typedef TriangularIterator iterator;
    // Note: 使用Iterator Class类对象
    iterator begin() const {
        return iterator(_beg_pos);
    }
    iterator end() const {
        return iterator(_beg_pos+_length);
    }

private:
    int _length;  // 元素个数
    int _beg_pos; // 起始位置
    // Note: mutable关键字，表示即便是const标记函数，也能更改它
    mutable int _next;    // 下一个迭代位置

    // Note: 类静态成员
    //     1. vector<int>这类这里这里仅是声明，它还必须拥有一份明确的定义（源文件中）
    //     2. int这类，可以在声明的时候给定初值，就不需要再次定义；否则需要定义
    static vector<int> _elems;
    const static int _max_elem_cnt=1024;
};

/*
 * Note: TriangularIterator基本是内联函数，所以都放在头文件中
 */
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
//Note: 运算符重载
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
#endif //CHAPTER4_TRIANGULAR_H
