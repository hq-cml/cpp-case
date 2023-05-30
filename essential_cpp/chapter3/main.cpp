#include <iostream>
#include <vector>
using namespace std;

// 在vector中找到目标数
//int *find(vector<int> &vec, int target) {
//    for (int i=0; i<vec.size(); i++) {
//        if (vec[i] == target) {
//            return &vec[i];
//        }
//    }
//    return 0;
//}
// 将上面的函数模板化，使得Vector不一定非要是int！
//template <typename T>
//T* find(vector<T> &vec, T target) {
//    for (int i=0; i<vec.size(); i++) {
//        if (vec[i] == target) {
//            return &vec[i];
//        }
//    }
//    return 0;
//}
// 将上面的函数进一步抽象，使他不再局限于Vector类型
// Note: 这里利用了C的一个特性即数组作为参数传入函数会退化指针
//       所以直接传入一个指针就相当于传入一个数组
//template <typename T>
//T* find(T *arr, int size, T target) {
//    if (!arr || size < 1) {
//        return 0;
//    }
//    for (int i=0; i<size; i++) {
//        if (arr[i] == target) {
//            return &arr[i];
//        }
//    }
//    return 0;
//}
// 更地道的优化，去除size参数，引入标兵指针
// Note: CPP的风格，是左闭右开，即不包括标兵指针
//       标兵仅用来进行比较，不能进行提领运算！
template <typename T>
T* find(T *first, T *end, T target) {
    if (!first || !end) {
        return 0;
    }
    for (T iter=first; iter!=end; iter++) { // 左闭右开
        if (*iter == target) {
            return iter;
        }
    }
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
