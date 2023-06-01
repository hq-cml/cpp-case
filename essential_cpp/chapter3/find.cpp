//
// Created by hq on 2023/5/31.
//
#include <iostream>
#include <vector>
#include <list>
#include "find.h"
using namespace std;

// 测试findWithIter函数的使用
void TestFindWithIter() {
    // 基本类型
    int arrInt[8] = {1,2,3,4,5,6,7,8};

    // vector类型
    vector<int> arrVec (arrInt, arrInt+8);

    // list类型
    list<int> arrList (arrInt, arrInt+8);

    // 普通类型使用
    int *pi = findWithIter(arrInt, arrInt+8, 7);
    if (pi!=arrInt+8) {
        cout << *pi << endl;
    } else {
        cout<< "not find in arrInt"<<endl;
    }

    // vector类型使用
    vector<int>::iterator it1 = findWithIter(arrVec.begin(), arrVec.end(), 4);
    if (it1!=arrVec.end()) {
        cout << *it1 << endl;
    } else {
        cout<< "not find in arrVec"<<endl;
    }

    // list类型使用
    list<int>::iterator it2 = findWithIter(arrList.begin(), arrList.end(), 10);
    if (it2!=arrList.end()) {
        cout << *it2 << endl;
    } else {
        cout<< "not find in arrList"<<endl;
    }
}

// 测试find函数的使用
void TestFind() {
    // 基本类型
    int arrInt[8] = {1,2,3,4,5,6,7,8};
    float arrFloat[8] = {1,2,3,4,5,6,7,8};
    string arrStr[4] = {"hello", "world", "cpp", "golang"};

    // vector类型
    vector<int> arrVec (arrInt, arrInt+8);

    // 基本类型使用
    int *pi = find(arrInt, arrInt+8, 3);
    cout << *pi << endl;
    float *pf = find(arrFloat, arrFloat+8, 3.0f);
    cout << *pf << endl;
    string need = "golang";
    string *ps = find(arrStr, arrStr+4, need);
    cout << *ps << endl;
    // vector类型使用
    int *pv = find(&arrVec[0], &arrVec[arrVec.size()], 4);
    cout << *pv << endl;
}
