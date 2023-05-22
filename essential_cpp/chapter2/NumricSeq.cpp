//
// Created by hq on 2023/5/21.
//
#include <vector>
#include <iostream>
#include "NumricSeq.h" // 如果不加这句，则display(vec)将报错

bool checkSize(int size);

using namespace std;

// 斐波那契数列
// Note: 返回值是一个指向常量的指针
const vector<int>* fibo_seq(int size) {

    // Note: 静态局部变量
    //     1. 内容只会初始化一次，分配在了静态区
    //     2. 在多次调用的时候都使用同一块内存
    static vector<int> elems;

    if (!checkSize(size)) {
        return NULL;
    }

    // 如果size小于elem.size则不需要重复建立，否则，只需要进行一次附加初始化
    for (int idx = elems.size(); idx < size; idx ++) {
        if (idx == 0){
            elems.push_back(0);
        } else if( idx == 1) {
            elems.push_back(1);
        } else {
            elems.push_back(elems[idx-1] + elems[idx-2]);
        }
    }
    return &elems;
}


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