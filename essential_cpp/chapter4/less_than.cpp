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
    LessThan lt10(10);
    cout << lt10(88)<<endl;
    cout << lt10(5)<<endl;
}

// Note: function object用来计数
int countLessThan(const vector<int> &vec, int base) {
    LessThan lt(base);
    int cnt = 0;
    for(int i=0; i<vec.size(); i++) {
        if (lt(vec[i])) {
            cnt ++;
        }
    }
    return cnt;
}

// Note: function object作为参数传递给泛型算法
//       在chapter3中有很多这样的用法
void printLessThan(const vector<int> &vec, int base) {
    LessThan lt(base);
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator end = vec.end();

    while((iter = find_if(iter, end, lt)) != end) {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
    return;
}

void TestLessThan () {
    simpleUse();

    int a[6] = {1,2,3,4,5,6};
    vector<int> vec(a, a+6);
    int cnt = countLessThan(vec, 4);
    cout << cnt << endl;

    printLessThan(vec, 5);
}