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
#include <iostream>
#include <set>
#include <map>
#include "container.h"
#include "find.h"

using namespace std;

// Note: Set的使用
//       1. Set的一个特点是：自动去重 & 排序！！
void UseSet() {
    set<int> iset1;
    int a [8] = {8,2,2,3,2,1,4,6};
    vector<int> vec (a, a+8);
    set<int> iset2(vec.begin(), vec.end()); // 初始化
    iset1.insert(vec.begin(), vec.end()); // 插入元素

    // Set迭代
    for(set<int>::iterator it=iset1.begin(); it!=iset1.end(); it ++) {
        cout << *it << " ";
    }
    cout << endl;
    for(set<int>::iterator it=iset2.begin(); it!=iset2.end(); it ++) {
        cout << *it << " ";
    }
    cout << endl;
}
// Note: Map的使用
//       1. map的元素不能随便读取，如果不存在会自动默认初始化！
//       2. 要读取，先用find或者count来判断存在性！
void UseMap() {
    map<string, int> words;
    words["foo"] = 1;
    words["bar"] = 2;

    // 遍历
    map<string, int>::iterator it = words.begin();
    for (; it != words.end(); it++) {
        cout << "Key:" << it->first<< ". Val:"<< it->second << endl;
    }

    // 判断key
    if(words.find("shit")!=words.end()) {
        cout << "exist"<<endl;
    } else {
        cout << "not exist"<<endl;
    }

    // 判断key的第二种方法
    if (words.count("foo")) {
        cout << "exist"<<endl;
    } else {
        cout << "not exist"<<endl;
    }
}

// 顺序容器初始化的方法
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

// 顺序容器的插入和删除
void InsertDel() {
    int a[] = {1,2,3,4};
    vector<int> oVec(a, a+4);

    // Note：尾部的插入和删除
    vector<int> v1(oVec.begin(), oVec.end());
    v1.push_back(5);
    Display(v1.begin(), v1.end());
    v1.pop_back();
    Display(v1.begin(), v1.end());

    // Note：指定为止插入
    vector<int>::iterator it = findV5(v1.begin(), v1.end(), 3);
    v1.insert(it, 88); // 在it前面插入
    Display(v1.begin(), v1.end());

    // Note：删除指定元素
    it = findV5(v1.begin(), v1.end(), 88);
    v1.erase(it);
    Display(v1.begin(), v1.end());
}

// Note:
//   顺序容器其他常用操作：判等、判空、求大小、清空等
void OtherOpt() {
    int a[] = {1,2,3,4};
    vector<int> v1(a, a+4);

    vector<int> v2;
    if (v2.empty()) {
        cout << "v2 is empty now"<<endl;
    }
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    if (v1==v2) {
        cout << "same"<<endl;
    } else {
        cout << "not same" <<endl;
    }

    v2.push_back(5);
    if (v1==v2) {
        cout << "same"<<endl;
    } else {
        cout << "not same" <<endl;
    }

    cout << "v2's len="<< v2.size()<<endl;
    v2.clear();
    cout << "v2's len="<< v2.size()<<endl;
}