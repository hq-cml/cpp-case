//
// Created by hq on 2023/5/21.
//
#include <vector>
#include <iostream>
#include "NumricSeq.h" // 如果不加这句，则display(vec)将报错

//bool checkSize(int size);

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


// 函数重载
void display_msg(char c) {
    cout << c<< endl;
}
void display_msg(const string &s) {
    cout << s << endl;
}
void display_msg(const string &s, int n) {
    cerr<<"invalid size:"<<n<<endl;
}

// 斐波那契数列: 0, 1, 1, 2, 3( pos从0开始计数）
// Note: 利用引用参数作为返回值，关于引用：
//      1. 本质上引用是指针的另一种使用形式，但也存在一点区别
//      2. 指针可以为空，也可以变更指向；引用不能为空引用，且从一而终，不能变更
//      3. 将引用作为函数的入参，本质上复制的是对象的地址
//      4. 引用作为参数的另一个好处是，避免了内存的大量拷贝
bool fibon_elem(int pos, int &elem) {
    // 生成足够数量的数列
    const vector<int>* pVec = fibo_seq(pos+1);
    if (!pVec) {
        elem = 0;
        return false;
    }
    // 返回需要的值
    elem = (*pVec)[pos];
    return true;
}

// 更扩展的版本，利用函数指针（使得生成数列不局限于斐波那契数列，其他数列也可以生成）
// Note: 函数指针
//       1. 这里参数中的(*seq_ptr)表示函数指针，实际测试直接写成seq_ptr也没问题
//       2. 函数名就是函数指针，所以函数名可以直接赋值给函数指针的变量
bool seq_elem(int pos, int &elem,
              const vector<int>* (*seq_ptr)(int)) {
    // Note：函数指针的使用，就是普通的函数调用
    const vector<int> *pVec = seq_ptr(pos+1);
    if (!pVec) {
        elem = 0;
        return false;
    }
    // 返回需要的值
    elem = (*pVec)[pos];
    return true;
}

// seq_arr变量的定义（用于extern关键字实验）
const vector<int> *(*seq_arr[])(int) = {
        fibo_seq
};

