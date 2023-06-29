//
// Created by hq on 2023/6/18.
//

#include "RTTI.h"
#include <typeinfo>

void TestRtti() {
    Father father;
    Son son;
    Father *p = &son;
    cout << father.WhoAmI() <<endl;
    cout << son.WhoAmI() <<endl;
    cout << typeid(father).name()<<endl; // Note: typeid直接使用
    cout << typeid(son).name()<<endl;
    cout << "--------------------"<<endl;
    cout << typeid(*p).name()<<endl;  // son
    // Note: typeid也可以直接用于判断类型是否相同
    if(typeid(*p) == typeid(Father)) {
        cout<< "is father"<<endl;
    } else if(typeid(*p) == typeid(Son)) {
        cout<<"is Son"<<endl;
    } else {
        cout <<"shit"<<endl;
    }
    cout << "--------------------"<<endl;
    p->OneFunc(); // 多态
    p->Father::OneFunc(); // Note: 绕开多态机制，强行静态调用父类虚函数
    // p->Son::OneFunc(); // Note: 编译报错，因为理论上此时p是父类指针，需要类型转换
    cout << "--------------------"<<endl;
    // Note: RTTI类型转换
    //      1. 类型转换两种形式：static_cast和dynamic_cast
    //      2. static_cast有安全隐患，因为编译器无法保证转换一定成功，所以一般要搭配typeid来预先确保
    //      2. dynamic_cast则可以直接根据转换结果判断，如果转换失败，则返回NULL指针
    if(typeid(*p) == typeid(Son)) {
        Son *ps = static_cast<Son *>(p);
        ps->OneFunc();
        ps->Son::OneFunc();
    }
    if(Son *ps = dynamic_cast<Son *>(p)) {
        ps->OneFunc();
        ps->Son::OneFunc();
    }
}