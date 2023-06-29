#include <iostream>
using namespace std;
// Note: 关于头文件是否用双引号
//      1. 双引号一般表示用户文件，编译器会优先扫描工程目录，没有再去库目录
//      2. 如果是<>，通常认为是库文件，编译器优先去扫描标准库目录
#include "NumricSeq.h"

// Note: 函数的声明，让编译器知道begin函数的存在。
void begin();
void UseVector();


//定义已经在头文件，所以不需要声明
//template <typename elemType>
//void display_elems(const string &msg, const vector<elemType> &vec);

int main() {

    //测试 extern关键字的使用
    //const vector<int>*v = seq_arr[0](10);
    //display(*v, cout);

    //const vector<int> *elems =  fibo_seq(10);
    //display(*elems);
    //display_elems("called by func template!", *elems);

    //UseVector();

    begin();
    return 0;
}

void begin() {
    int pos;
    while(1){
        cout << "Please input a pos:";
        cin >> pos;

        int elem;
        //if(fibon_elem(pos, elem)) {
        // Note: 函数名就是函数指针，所以函数名可以直接赋值给函数指针的变量
        if(seq_elem(pos, elem, fibo_seq)) {
            cout << "Elem #" << pos << " is " << elem <<endl;
        } else {
            cout << "Sorry. Invalid pos:"<<pos<<endl;
        }
    }
}

// 演示vector基本使用
void UseVector() {
    int arr[8] = { 1, 8, 9, 2, 3,4 , 7, 9};
    vector<int> vec (arr, arr+8); // Note：使用list来初始化vector
    display(vec); // 有默认值
}
