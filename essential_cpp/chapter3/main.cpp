/*
 * chapter3：泛型的编程风格
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

#include "find.h"
#include "container.h"
#include "algorithms.h"
using namespace std;

void file_sort();

int main() {
    //file_sort();
    //UseSet();
    //UseMap();
    //TestFuncObj();
    TestAlg();
    //CommonAlg();
    //OtherOpt();
    //InsertDel();
    //TestFindWithIter();
    //TestFind();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Note: iostream迭代器
//      使用io迭代器实现了文件排序
//      istream_iterator：标准库定义的输入迭代器
//      ostream_iterator：标准库定义的输出迭代器
void file_sort() {
    ifstream inFile("input.txt");
    ofstream outFile("out.txt");
    if(!inFile || !outFile) {
        cerr<<"open failed"<<endl;
        return;
    }

    // 读取文件到content
    istream_iterator< string > is(inFile);
    istream_iterator< string > eof; // Note: 不加任何参数的初始化，标志着EOF
    vector<string> content;
    copy (is, eof, back_inserter(content)); // Note: back_inserter它处解释

    // 排序
    sort(content.begin(), content.end());

    // 写入文件
    ostream_iterator<string> os(outFile, " ");
    copy(content.begin(), content.end(), os);
}