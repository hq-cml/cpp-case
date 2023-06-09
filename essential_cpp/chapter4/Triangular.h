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
    bool next(int &v) const;
    void next_reset() const {_next = _beg_pos - 1;}

    // 非const标记成员函数
    Triangular& copy(const Triangular& src);
    void Temp(); // 测试一下静态成员声明和定义

    // Note: 类静态成员函数
    static void gen_elems_to_value(int value);
    static void gen_elems(int len);
    static void display(ostream &os = cout);
    static bool has_elem(int val);

    // TMP:临时放在这里，有了友元之后放回去
    static vector<int> _elems;
    const static int _max_elem_cnt=1024;
private:
    int _length;  // 元素个数
    int _beg_pos; // 起始位置
    mutable int _next;    // 下一个迭代位置 Note: mutable表示即便是const标记函数，也能更改它

    // Note: 类静态成员
    //     1. vector<int>这类这里这里仅是声明，它还必须拥有一份明确的定义（源文件中）
    //     2. int这类，可以在声明的时候给定初值，就不需要再次定义；否则需要定义
//    static vector<int> _elems;
//    const static int _max_elem_cnt=1024;
};


#endif //CHAPTER4_TRIANGULAR_H
