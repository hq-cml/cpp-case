//
// Created by hq on 2023/6/18.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*************************** BNode ***********************/
template<typename valType>
void BNode<valType>::
insert_value(const valType& val) {
    if (val == _val) {
        _cnt ++;
    } else if (val <_val) {
        if (!_lchild) {
            _lchild = new BNode(val);
        } else {
            _lchild->insert_value(val);
        }
    } else {
        if (!_rchild) {
            _rchild = new BNode(val);
        } else {
            _rchild->insert_value(val);
        }
    }
}

template<typename valType>
void BNode<valType>::
Pre(BNode *pt) {
    if (pt) {
        cout << pt->_val;
        Pre(pt->_lchild);
        Pre(pt->_rchild);
    }
}

template<typename valType>
void BNode<valType>::
Mid(BNode *pt) {
    if (pt) {
        Mid(pt->_lchild);
        cout << pt->_val;
        Mid(pt->_rchild);
    }
}

/*************************** BinaryTree ***********************/
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

// insert
template<typename elemType>
inline void BinaryTree<elemType>::
insert(const elemType &elem) {
    if (!_root) {
        _root = new BNode<elemType>(elem);
    } else {
        _root->insert_value(elem);
    }
}

// Pre
template<typename elemType>
inline void BinaryTree<elemType>::
Pre() {
    _root->Pre(_root);
    cout << endl;
}

// Mid
template<typename elemType>
inline void BinaryTree<elemType>::
Mid() {
    _root->Mid(_root);
    cout << endl;
}

void TestBTree() {
    BinaryTree<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);

    tree.Pre();
    tree.Mid();
}