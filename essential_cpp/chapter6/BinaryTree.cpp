//
// Created by hq on 2023/6/18.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;

// 构造函数
template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree():_root(0){
    cout << "Tree Construct"<<endl;
}

// 拷贝构造
template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree(const BinaryTree &src) {
    cout << "Tree Copy Construct"<<endl;
    copy(_root, src._root);
}

// 析构
template<typename elemType>
inline BinaryTree<elemType>::
~BinaryTree() {
    cout << "Tree Destruct"<<endl;
}

// 拷贝赋值
template<typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::
operator=(const BinaryTree& src) {
    if (this!=src) {
        clear();
        copy(_root, src._root);
    }
    return *this;
}