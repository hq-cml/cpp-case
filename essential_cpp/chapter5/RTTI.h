//
// Created by hq on 2023/6/18.
//

#ifndef CHAPTER5_RTTI_H
#define CHAPTER5_RTTI_H

#include <iostream>
#include <typeinfo>

using namespace std;

void TestRtti();

class Father {
public:
    // Note: typeid运算符
    //       类似于golang的reflect
    //       用法1：可以用.name()方法返回字符串类型的类名字，如下
    //       用法2：也可以直接用于判断类型是否相同
    virtual const char* WhoAmI() {
        return typeid(*this).name();
    }
    virtual void OneFunc() {
        cout << "Father call func"<<endl;
    }
};


class Son:public Father{
public:
    virtual void OneFunc() {
        cout << "Son call func"<<endl;
    }
};

#endif //CHAPTER5_RTTI_H
