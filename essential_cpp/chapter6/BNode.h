//
// Created by hq on 2023/6/18.
//

#ifndef CHAPTER6_BNODE_H
#define CHAPTER6_BNODE_H

// Note: 前置声明
template <typename Type>
class BinaryTree;

template <typename valType>
class BNode {
    friend class BinaryTree<valType>; //Note: 友元类
public:
private:
    valType _val;
    int _cnt;
    BNode *_lchild;
    BNode *_rchild;
};


#endif //CHAPTER6_BNODE_H
