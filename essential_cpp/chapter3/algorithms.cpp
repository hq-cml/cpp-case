//
// Created by hq on 2023/6/4.
//

#include "algorithms.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include "container.h"

using namespace std;
// Note: 系统内置常用泛型算法
//       find(): 搜索无序集合（其实有序的更可以）
//       binary_search(): 搜索有序集合，返回bool（必须是有序的，否则出错）
//       count()：返回需要搜搜的元素的数量
//       max_element()：返回数列最大值
//       copy()：复制容器
//       sort()：排序
void CommonAlg() {
    int a[] = {4,1,3,2};
    vector<int> v1(a, a+4);
    vector<int>::iterator it = find(v1.begin(), v1.end(), 3);
    cout<<*it<<endl;

    int b[] = {1,2,3,4};
    vector<int> v2(b, b+4);
    bool exist = binary_search(v1.begin(), v1.end(), 1); //无序容器搜索失败
    cout<<exist<<endl;
    exist = binary_search(v2.begin(), v2.end(), 1);
    cout<<exist<<endl;

    int c = count(v1.begin(), v1.end(), 3);
    cout<<c<<endl;
    c = count(v1.begin(), v1.end(), 88);
    cout<<c<<endl;

    it = max_element(v1.begin(), v1.end());
    cout<<*it<<endl;

    vector<int> tmp(v1.size());
    copy(v1.begin(), v1.end(), tmp.begin()); //复制
    Display(tmp.begin(), tmp.end());
    sort(tmp.begin(), tmp.end());    // 排序
    Display(v1.begin(), v1.end());   // 不影响
    Display(tmp.begin(), tmp.end()); // 已排序
}
