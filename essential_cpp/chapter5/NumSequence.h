//
// Created by hq on 2023/6/11.
//

#ifndef CHAPTER5_NUMSEQUENCE_H
#define CHAPTER5_NUMSEQUENCE_H

#include <iostream>
using namespace std;

// Note: 关于virtual
//       1. static成员函数不能为虚virtual，因为它不受限于某个对象
//       3. 构造函数不能是virtual
//       4. 如果父类函数是virtual，则继承体系下的子类同名函数都自动virtual
//       5. 子类函数可加virtual也可不加，但是最好是加上
//       6. virtual只需要在声明的时候用，在类外进行定义实现的时候不需要再加
class NumSequence {
public:
    // Note: 构造函数
    //       本类没有非static成员变量，所以没有必要定义构造函数
    // Note: 虚析构
    //       通常虚析构不定义为纯虚函数，这里给出空定义
    virtual ~NumSequence(){};

    // Note: 纯虚函数 = 0
    //      1. 一个类一旦有1个纯虚函数，它就成为了抽象类，不能实例化
    //      2. 只能用于派生，它的子类必须实现所有的纯虚函数，才能实例化
    virtual int elem(int pos) const=0;                    // 返回pos位置的元素
    virtual const char * what_am_i() const=0;             //返回确切的数列类型
    virtual ostream &print(ostream &os=cout) const=0;     // 输出所有元素

    // Note: static成员函数不能为虚virtual
    static int max_elems(){return _max_elems;}            // 返回支持最大元素

protected:
    virtual void gen_elems(int pos) const =0;                    // 产生直到pos位置的所有元素
    bool check_integrity(int pos, int size) const;                  // 检查pos是否为有效位置
    const static int _max_elems = 1024;                   //
};

// 声明
ostream &operator<<(ostream &os, const NumSequence &ns);

#endif //CHAPTER5_NUMSEQUENCE_H
