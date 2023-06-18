//
// Created by hq on 2023/6/18.
//

#ifndef CHAPTER7_EXCEPTION_H
#define CHAPTER7_EXCEPTION_H
#include <iostream>
#include <exception>

using namespace std;

void TestExcp();
// Note: 通常，异常都是一个类
class IteratorOverflow {
public:
    IteratorOverflow(int idx, int max):_idx(idx),_max(max){}
    void whatHappend(ostream &os=cerr) {
        os << "Error:"<<_idx<<" exceeds "<<_max<<endl;
    }
private:
    int _idx;
    int _max;
};

// Note: 标准异常类
//    1. 所有的标准异常都继承自Exception（它定义了一些虚函数）
//    2. 可以自己实现一个类继承Exception，然后覆盖虚函数
class MyException: public exception {
public:
    MyException(string s):_msg(s){}
    // Note：覆盖基类的what()
    //      PS：需要加上throw()语句，可能是新规范
    virtual const char* what() const throw() {
        string msg = "MyExcp:"+_msg;
        return msg.c_str();
    }
private:
    string _msg;
};

#endif //CHAPTER7_EXCEPTION_H
