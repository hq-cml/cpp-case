#include <iostream>
#include <vector>
using namespace std;

// 在vector中找到目标数
//int *find(vector<int> &vec, int target) {   // v1.0
//    for (int i=0; i<vec.size(); i++) {
//        if (vec[i] == target) {
//            return &vec[i];
//        }
//    }
//    return 0;
//}
// 将上面的函数模板化，使得Vector不一定非要是int！
//template <typename T>                       // v2.0
//T* find(vector<T> &vec, T target) {
//    for (int i=0; i<vec.size(); i++) {
//        if (vec[i] == target) {
//            return &vec[i];
//        }
//    }
//    return 0;
//}
// 将上面的函数进一步抽象，使他不再局限于Vector类型
// NOTE: 这里利用了C的一个特性即数组作为参数传入函数会退化指针
//       所以直接传入一个指针就相当于传入一个数组
//template <typename T>                        // v3.0
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
template <typename T>                          // v4.0
T* find(T *first, T *end, T target) {
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

int main() {
    UseFind();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
