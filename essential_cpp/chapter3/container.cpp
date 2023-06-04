//
// Created by hq on 2023/6/4.
//
// 常用容器的使用例子
// Note: vector，底层是一段连续内存
// Note: list，底层是一个双向链表
// Note: deque，底层也是一段连续内存，但是对于头、尾元素的插入删除，效率高于vector

#include <vector>
#include <list>
#include <deque>
#include <string>
#include "container.h"

using namespace std;

// 容器初始化的方法
void Init() {
    // Note：产生空容器
    list<string> slist;
    vector<int> ivec;

    // Note: 产生指定大小的容器（初始值默认使用0值填充）
    list<string> silist(10);
    vector<int> iivec(1024);

    // Note：产生指定大小的容器，并指定初始值
    list<string> ssilist(10, "tobe replace");
    vector<int> iiivec(1024, -1);

    // Note: 通过iterator初始化容器（iterator指明起、止为止，左闭右开）
    int a[] = {1,2,3,4};
    vector<int> iiiivec(a, a+4);
    vector<int> iiiiivec(iiivec.begin(), iiivec.end());

    // Note：根据另一个容器进行初始化
    list<string> ssslist(ssilist);
}