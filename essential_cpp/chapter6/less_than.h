//
// Created by hq on 2023/6/18.
//

#ifndef CHAPTER6_LESS_THAN_H
#define CHAPTER6_LESS_THAN_H

#include <algorithm>
void TestLessThan ();
void TestLessThanPred();
using namespace std;

//Note: chapter4定义过一个LessThan，不过那个是普通类
//      不是模板类，这里定义类模板
template<typename elemType>
class LessThan {
public:
    LessThan(const elemType &val):_val(val) {}
    // Note：重载()运算符
    bool operator()(const elemType &val) const {
        return val < _val;
    }
private:
    elemType _val;// 基
};

//Note: 进一步通用化！
//     1. 上面的LessThan有一个局限，因为是模板类，如果用户传入了一个不支持比大小的类型，比如string，则会出错
//     2. 所以还可以进一步的抽象通用化，引入模板的第二个参数
//     3. 模板参数也可以有默认值，例如这里的 typename Comp = less<elemType>
template<typename elemType, typename Comp = less<elemType> >
class LessThanPred {
public:
    LessThanPred(const elemType &val):_val(val) {

    }
    // Note：重载()运算符
    bool operator()(const elemType &val) const {
        return Comp()(val, _val);
    }
private:
    elemType _val;// 基
};

// 用于字符串的比较
class StringComp {
public:
    StringComp() {
        cout << "xxx----";
    }
    bool operator()(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }
};
#endif //CHAPTER6_LESS_THAN_H
