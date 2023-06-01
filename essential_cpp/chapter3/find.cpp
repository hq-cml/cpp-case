//
// Created by hq on 2023/5/31.
//
#include <iostream>
#include <vector>
#include "find.h"
using namespace std;

// 测试find函数的使用
void UseFind() {
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
