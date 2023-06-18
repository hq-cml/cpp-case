//
// Created by hq on 2023/6/18.
//

#ifndef CHAPTER6_BINARYTREE_H
#define CHAPTER6_BINARYTREE_H

void TestBTree();

/*************************** BNode ***********************/
// Note: 前置声明
template <typename Type>
class BinaryTree;

template <typename valType>
class BNode {
    friend class BinaryTree<valType>; //Note: 友元类
public:
    BNode();
    BNode(const valType &val);
    void insert_value(const valType &val);
    void Pre(BNode *pt);
    void Mid(BNode *pt);
private:
    valType _val;
    int _cnt;
    BNode *_lchild;
    BNode *_rchild;
};

// Note：对于成员变量是模板变量的，
//      初始化应该尽量使用初始化器，便于性能提升，原因如下：
//      模板类型如果是一个普通类型，那么其实没区别，但是，如果
//      模板类型是一个类，那么使用初始化器则仅进行了一次拷贝构造
//      如果不适用初始化器，在构造函数内部其实是默认构造函数+拷贝赋值（多了一次）
template <typename valType>
inline BNode<valType>::
BNode(const valType &val):_val(val) {
    //_val = val; // 不建议！性能低
    _cnt = 1;
    _lchild = _rchild = 0;
}

/*************************** BinaryTree ***********************/
template <typename elemType>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree&);

    bool empty() {
        return _root == 0; //Note: 内联
    }

    void clear();
    void insert(const elemType &elem);

    void Pre();
    void Mid();
private:
    BNode<elemType> *_root;
    void copy(BNode<elemType> *dst, BNode<elemType> *src); //src子树复制到dst子树
};

#endif //CHAPTER6_BINARYTREE_H
