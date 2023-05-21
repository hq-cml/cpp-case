//
// Created by hq on 2023/5/21.
//
#include <vector>
#include <iostream>
#include "NumricSeq.h" // 如果不加这句，则display(vec)将报错

using namespace std;
// Note: 函数定义
//     1. 函数定义通常放在源文件中，最终会被编译和链接
//     2. 参数默认值放在声明中，这里不需要再写
void display(const vector<int> &vec, ostream & os) {
    for (int idx = 0; idx < vec.size(); idx ++) {
        os << vec[idx] << " ";
    }
    os << endl;
}

// 演示vector基本使用
void UseVector() {
    int arr[8] = { 1, 8, 9, 2, 3,4 , 7, 9};
    vector<int> vec (arr, arr+8); // Note：使用list来初始化vector
    display(vec); // 有默认值
}