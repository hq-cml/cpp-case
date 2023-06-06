//
// Created by hq on 2023/6/5.
//

#ifndef CHAPTER4_TRIANGULAR_H
#define CHAPTER4_TRIANGULAR_H
#include <vector>
using namespace std;

void TestUseTrangular();

class Triangular {
public:
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

    // 非const成员函数
    bool next(int &v);
    void next_reset() {_next = _beg_pos - 1;}
private:
    int _length;  // 元素个数
    int _beg_pos; // 起始位置
    int _next;    // 下一个迭代位置

    static vector<int> _elems;
};


#endif //CHAPTER4_TRIANGULAR_H
