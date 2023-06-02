//
// Created by hq on 2023/5/31.
//

#ifndef CHAPTER3_FIND_H
#define CHAPTER3_FIND_H

#include <vector>
using namespace std;

void TestFind();
void TestFindWithIter();

// v1.0没有函数模板，只能定义在源文件中，否则会链接错误
// 将上面的函数模板化，使得Vector不一定非要是int！
template <typename T>                       // v2.0
T* findV2(vector<T> &vec, T target) {
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] == target) {
            return &vec[i];
        }
    }
    return 0;
}

// 将上面的函数进一步抽象，使他不再局限于Vector类型
// NOTE: 这里利用了C的一个特性即数组作为参数传入函数会退化指针
//       所以直接传入一个指针就相当于传入一个数组
template <typename T>                        // v3.0
T* findV3(T *arr, int size, T target) {
    if (!arr || size < 1) {
        return 0;
    }
    for (int i=0; i<size; i++) {
        if (arr[i] == target) {
            return &arr[i];
        }
    }
    return 0;
}

// 更地道的优化，去除size参数，引入标兵指针
// Note: CPP的风格，是左闭右开，即不包括标兵指针
//       标兵仅用来进行比较，不能进行提领运算！
template <typename T>                          // v4.0
T* findV4(T *first, T *end, T target) {
    if (!first || !end) {
        return 0;
    }
    for (T *iter=first; iter!=end; iter++) { // 左闭右开
        if (*iter == target) {
            return iter;
        }
    }
    return 0;
}

// Note：迭代器 Iterator
// v4.0虽然已经很优雅，但是仍然有进一步抽象通用化的空间
// 比如find只能接受内存连续的类型，如数组、vector等类型，如果要是list类型，就不支持了
// 要想支持list，需要进一步的抽象，对于指针类型进行封装，使得指针的++、*等操作能够针对底层不同类型而不同
// 引入了iterator class来代替指针，它能够实现千人千面，根据底层不同类型来实现不同的++、*等操作
// 此外，标准容器，都提供了begin()，end()等方法来获取到对应的iterator，如下
// vector<int> vecInt;
// vector<int>::it = vecInt.begin()
template<typename ItType, typename T>
ItType findV5(ItType first, ItType last, T target) {
    for (ItType iter=first; iter!=last; iter++) {
        if (*iter == target) {
            return iter;
        }
    }
    return last;
}


#endif //CHAPTER3_FIND_H
