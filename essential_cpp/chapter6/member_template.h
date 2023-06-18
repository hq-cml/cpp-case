//
// Created by hq on 2023/6/18.
//

#ifndef CHAPTER6_MEMBER_TEMPLATE_H
#define CHAPTER6_MEMBER_TEMPLATE_H
#include <iostream>
using namespace std;

void TestMemberTemplate();

// Note: 普通类中，成员函数可以函数模板
class PrintIt {
public:
    PrintIt(ostream &os):_os(os){}

    template<typename elemType>
    void print(const elemType &elem, char delime = '\n') {
        _os << elem << delime;
    }
private:
    ostream &_os;
};

//Note: 类模板+成员函数模板
template<typename osType>
class PrintItV2 {
public:
    PrintItV2(osType& os):_os(os){}

    template<typename elemType>
    void print(const elemType &elem, char delime = '\n') {
        _os << elem << delime;
    }
private:
    osType& _os;
};

#endif //CHAPTER6_MEMBER_TEMPLATE_H
