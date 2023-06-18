//
// Created by hq on 2023/6/18.
//
#include <iostream>
#include "less_than.h"
using namespace std;

void simpleUse() {
    // Note: 模板类的使用：LessThan<int>
    LessThan<int> lt_10(10);
    cout << "lt_10(10)(80): " << lt_10(88)<<endl;
    cout << "lt_10(10)(5): " << lt_10(5)<<endl;

    // Note: 其实这就等价于bind2nd(less<int>(), 10)
    cout << "bind2nd(less<int>(), 10)(88): " << bind2nd(less<int>(), 10)(88)<<endl;
    cout << "bind2nd(less<int>(), 10)(5): " << bind2nd(less<int>(), 10)(5)<<endl;

    // Note: 进一步等价
    cout << less<int>()(88,10) << endl;
    cout << less<int>()(5,10) << endl;
}

void TestLessThanPred() {
    LessThanPred<int> lt1(10);
    cout << "lt1(80): " << lt1(88)<<endl;
    cout << "lt1(5): " << lt1(5)<<endl;

    LessThanPred<int, less<int> > lt2(10);
    cout << "lt2(80): " << lt2(88)<<endl;
    cout << "lt2(5): " << lt2(5)<<endl;

    // 运算符()参数数量不匹配，所以用不了
//    LessThanPred<int, LessThan<int> > lt3(10);
//    cout << "lt3(10)(80): " << lt3(88)<<endl;
//    cout << "lt3(10)(5): " << lt3(5)<<endl;

    LessThanPred<string, StringComp> lt4("Hello");
    cout << "lt4(80): " << lt4("hello world")<<endl;
    cout << "lt4(5): " << lt4("hel")<<endl;
}

void TestLessThan () {
    //simpleUse();
    TestLessThanPred();
}