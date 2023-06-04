//
// Created by hq on 2023/6/4.
//
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

#ifndef CHAPTER3_ALGORITHMS_H
#define CHAPTER3_ALGORITHMS_H

void CommonAlg();
void TestAlg();
void TestFuncObj();

// v2仍然不够地道，现在需要用泛型算法find_if来实现
// Note: 为了更加通用，同时使用了模板、函数对象和适配器等
//       这个函数已经是彻头彻尾的三无关：元素类型无关、比较操作无关、容器类型无关
//       但是，这种完全没有可读性，而且使用也很麻烦
template <typename InIter, typename OutInter, typename ElemT, typename Comp>
int filter_v3(InIter first, InIter last, OutInter at, const ElemT &val, Comp pred) {
    int cnt = 0;
    while((first=find_if(first, last, bind2nd(pred, val)))!=last) {
        // 找到一个，赋值
        cout<<"found: "<<*first<<endl;
        *at++ = *first++;
        cnt ++;
    }
    return cnt;
}


#endif //CHAPTER3_ALGORITHMS_H
