//
// Created by hq on 2023/6/18.
//

#ifndef CHAPTER6_BINARYTREE_H
#define CHAPTER6_BINARYTREE_H

// Note: 前置声明
template <typename Type>
class BNode;

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

private:
    BNode<elemType> *_root;
    void copy(BNode<elemType> *dst, BNode<elemType> *src); //src子树复制到dst子树
};

#endif //CHAPTER6_BINARYTREE_H
