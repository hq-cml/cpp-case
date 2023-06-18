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
Pre(BNode *pt, ostream &os) {
    if (pt) {
        os << pt->_val;
        Pre(pt->_lchild, os);
        Pre(pt->_rchild, os);
    }
}

template<typename valType>
void BNode<valType>::
Mid(BNode *pt,ostream &os) {
    if (pt) {
        Mid(pt->_lchild, os);
        os << pt->_val;
        Mid(pt->_rchild,os );
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

// print，实现很抽象
template <typename elemType>
ostream& BinaryTree<elemType>::
print( ostream &os, void (BinaryTree::*func)(ostream &os) const ) const {
    (this->*func)(os);
    return os;
}

// Pre
template<typename elemType>
inline void BinaryTree<elemType>::
Pre(ostream &os) const {
    _root->Pre(_root, os);
    os << endl;
}

// Mid
template<typename elemType>
inline void BinaryTree<elemType>::
Mid(ostream &os) const {
    _root->Mid(_root, os);
    os << endl;
}

// Note: 利用函数模板+类模板实现了<<的重载
//       1. print()函数的视线非常抽象
template<typename elemType>
ostream& operator<<(ostream &os, const BinaryTree<elemType> &tree) {
    os << "Tree: ";
    tree.print(os);
    return os;
}

void TestBTree() {
    BinaryTree<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);

    tree.Pre(cout);
    tree.Mid(cout);
    //tree.print(cout);
    cout << tree;
}