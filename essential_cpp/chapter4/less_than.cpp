//
// Created by hq on 2023/6/11.
//
#include <iostream>
#include <vector>
#include "less_than.h"
#include <algorithm>

using namespace std;

// Note: function object最简单使用
//       1. 这里lt10，是一个对象，它的基数是10
//       2. 所以，编译器会将诸如lt10(88)，翻译成lt10.operator()(88)
void simpleUse() {
    LessThan lt_10(10);
    cout << "lt_10(10)(80): " << lt_10(88)<<endl;
    cout << "lt_10(10)(80): " << lt_10.operator()(88)<<endl; // 等价
    cout << "lt_10(10)(5): " << lt_10(5)<<endl;
    cout << "lt_10(10)(5): " << lt_10.operator()(5)<<endl; // 等价

    // Note: 其实这就等价于bind2nd(less<int>(), 10)
    cout << "bind2nd(less<int>(), 10)(88): " << bind2nd(less<int>(), 10)(88)<<endl;
    cout << "bind2nd(less<int>(), 10)(5): " << bind2nd(less<int>(), 10)(5)<<endl;

    // Note: 进一步等价
    cout <<"less<int>()(88,10) "<< less<int>()(88,10) << endl;
    cout <<"less<int>()(5,10) "<< less<int>()(5,10) << endl;
}

// Note: function object用来计数
int countLessThan(const vector<int> &vec, int base) {
    LessThan lt(base);
    int cnt = 0;
    for(int i=0; i<vec.size(); i++) {
        //if (lt.operator()(vec[i])) { //等价
        if (lt(vec[i])) {
            cnt ++;
        }
    }
    return cnt;
}
bool less_than_5(int v) {
    return v < 5;
}

// Note: function object作为参数传递给泛型算法
//       在chapter3中有很多这样的用法
void printLessThan(const vector<int> &vec, int base) {
    LessThan lt(base);
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator end = vec.end();

    cout << "LessThan lt(base): ";
    while((iter = find_if(iter, end, lt)) != end) {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;

    // Note: 两种等价，好好对比体会!
    //       等价1：官方提供的function object，配合bind2nd适配器
    //       等价2: 自己写的函数，不过自己写的函数达不到闭包效果，参数5是写死的
    //       传给find_if的第3个参数，xx是个泛型，可以是一个函数，也可以是是个函数对象（只要xx()可以解释得通就行）

    // 等价1
    iter = vec.begin();
    end = vec.end();
    cout << "bind2nd(less<int>(), base): ";
    while((iter = find_if(iter, end, bind2nd(less<int>(), base))) != end) {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;

    // 等价2
    iter = vec.begin();
    end = vec.end();
    cout << "less_than_5: ";
    while((iter = find_if(iter, end, less_than_5)) != end) {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
    return;
}

void TestLessThan () {
    simpleUse();
    cout << "--------------------------"<<endl<<endl;
    int a[6] = {1,2,3,4,5,6};
    vector<int> vec(a, a+6);
    int cnt = countLessThan(vec, 4);
    cout << cnt << endl;
    cout << "--------------------------"<<endl<<endl;
    printLessThan(vec, 5);
}