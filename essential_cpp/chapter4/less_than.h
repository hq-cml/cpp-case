//
// Created by hq on 2023/6/11.
//

#ifndef CHAPTER4_LESS_THAN_H
#define CHAPTER4_LESS_THAN_H
/*
 * Note：function object. 括号的运算符重载
 *      1. 当编译器遇到一个函数调用语法：xxx()
 *      2. 此时xxx可能是3种情况：函数 & 函数指针 & 重载了()的function对象
 *      3. 即，本质上xxx是一个类对象，且这个类重载了函数运算符()
 *      4. 此时，编译器内部，会转换成语句：xxx.operator()()
 *         第一个括号是函数名字的一部分，第二个括号是参数列表
 *      5. function object的使用，有点类似于Go的闭包
 */
class LessThan {
public:
    LessThan(int val):_val(val) {};
    // Note：重载()运算符
    //       1. 注意这里的operator()是一个完整的名字字符串，包括这个()也是名字的一部分
    //       2. 这个函数的参数列表是(int v)
    bool operator()(int v) const;
private:
    int _val; // 基数
};

inline bool LessThan::operator()(int v) const {
    return v < _val;
}

void TestLessThan();

#endif //CHAPTER4_LESS_THAN_H
