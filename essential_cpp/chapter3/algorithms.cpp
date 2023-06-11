//
// Created by hq on 2023/6/4.
//

#include "algorithms.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <iterator>
#include "container.h"

using namespace std;

// Note: 设计一个自己的泛型算法
//       例如：实现过滤功能
vector<int> filter_v1(const vector<int> &vec, int target) {
    vector<int> ret;
    for (int idx = 0; idx<vec.size(); idx++){
        if (vec[idx]<target) {
            ret.push_back(vec[idx]);
        }
    }
    return ret;
}

// v1只支持固定<比较，要将比较通用化，引入v2
vector<int> filter_v2(const vector<int> &vec, int target,
                      bool (*pred)(int, int)) {
    vector<int> ret;
    for (int idx = 0; idx<vec.size(); idx++){
        if (pred(vec[idx], target)) {
            ret.push_back(vec[idx]);
        }
    }
    return ret;
}
bool less_than(int v1, int v2) {
    return v1 < v2;
}
bool greater_than(int v1, int v2) {
    return v1 > v2;
}

// 测试
void TestAlg() {
    int a[] = {1,3,2,4,8,5,7,6};
    vector<int> v0(a, a+8);
    vector<int> tmp = filter_v2(v0, 4, less_than);
    Display(tmp.begin(), tmp.end());

    // 为了通用性，牺牲了太多的可读性和使用的方便性，并不值得
    vector<int> v1(8);
    int cnt = filter_v3(v0.begin(), v0.end(), v1.begin(), 5, greater<int>());
    cout <<"Found---"<< cnt <<endl;
    Display(v1.begin(), v1.end());

    // 上面的使用方式很显然存在一个问题，就是v1需要初始化8个元素防止内存越界，实际上这形成了很多浪费
    // Note: Iterator Inserter(迭代插入器）
    //       作用就是解决这种问题，使得不需要提前分配空间，原理是将赋值操作替换为插入操作！
    //       共有三种：
    //       back_inserter：将filter_v3内的at++，篡改替换成了push_back()
    //       inserter：将filter_v3内的at++，篡改成指定为止的插入
    //       front_inserter：将filter_v3内的at++，篡改替换成了push_front()
    vector<int> v2; // 无需初始，避免浪费
    cnt = filter_v3(v0.begin(), v0.end(), back_inserter(v2), 5, greater<int>());
    cout <<"Found---"<< cnt <<endl;
    Display(v2.begin(), v2.end());
}

// Note: function object（函数对象）
//       函数对象是某些类的实例，由于这些类重载了函数调用操作符，即()，所以函数对象可以当做函数来使用
//       它的好处是效率更高，默认是内联的，chapter4中有更详细的解释
//       标准库有三类函数对象：
//         运算符（6个）：puls<type>, minus<type>...
//         关系符（6个）：less<type>, greater<type>, equal_to<type>, less_equal<type>...
//         逻辑符（3个）：logical_and<type>, logical_or<type>, logical_not<type>..
// Note：函数对象适配器（function object adapter）
//       通常配合函数对象来使用，主要的作用是二元转一元运算，取反等等
//         bind2nd：将二元转一元运算，参数绑定在第2个参数上
//         bind1st：将二元转一元运算，参数绑定在第1个参数上
//         not1: 结果取反
void TestFuncObj() {
    int a[] = {4,1,3,2};
    vector<int> v1(a, a+4);
    sort(v1.begin(), v1.end());
    Display(v1.begin(), v1.end());

    // Note：利用函数对象实现降序排列
    sort(v1.begin(), v1.end(), greater<int>());
    Display(v1.begin(), v1.end());

    // Note: find_if使用，扫描出所有小于6的数字
    int aa[] = {1,3,2,4,8,5,7,6};
    vector<int> vec(aa, aa+8);
    vector<int> ret;
    vector<int>::iterator it = vec.begin();
    // Note: bind2nd
    // 6被绑定到了less<int>第二个参数上面，所以这里每个成员都会和6比大小
    while ((it = find_if(it, vec.end(), bind2nd(less<int>(), 6)))!=vec.end()){
        ret.push_back(*it);
        it++;
    }
    Display(ret.begin(), ret.end());
}

// Note: 系统内置常用泛型算法
//       find(): 搜索无序集合（其实有序的更可以）
//       binary_search(): 搜索有序集合，返回bool（必须是有序的，否则出错）
//       count()：返回需要搜搜的元素的数量
//       max_element()：返回数列最大值
//       copy()：复制容器
//       sort()：排序
//       find_if(): 从容器中，找到合适的元素，条件可以通过第二个参数指定，例子见：TestFuncObj
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
