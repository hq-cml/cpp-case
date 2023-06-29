//
// Created by hq on 2023/6/18.
//
#include "exception.h"

void ThrowExcp(int choose);
void CatchExcp(int choose);

void TestExcp() {
    CatchExcp(0);
    CatchExcp(1);
    CatchExcp(2);
    //CatchExcp(3);

    try {
        throw MyException("fuck");
    } catch (exception &ex){
        cout << ex.what();
    }
}

// Note：异常捕获
//      1. 按类型捕获，可以用...进行兜底；另一种兜底方案是捕获excetion基类
//      2. 用语句 throw; 可以二次抛出异常
//      3. 因为C++中没有finally，所以在出现异常的情况下，对于资源的释放，无法自动进行！！
//         解决办法是将资源释放移动到析构函数中（析构函数由CPP保证无论异常与否都会调用）！！
void CatchExcp(int choose) {
    try {
        ThrowExcp(choose);
    }catch(int erno) {
        cout << "catch int "<< erno << endl;
    }catch (const char *s) {
        cout << "catch char* "<< s << endl;
    }catch (IteratorOverflow &ex) {
        cout << "catch IteratorOverflow: ";
        ex.whatHappend(cout);
    }catch (...) { // 兜底
        cout << "Unknow...";
        throw; // 二次抛出
    }
}

// Note: 异常抛出
//      1. 通常异常都是一个类，但是实际上可以是任意类型
void ThrowExcp(int choose) {
    if(choose == 0)  {
        throw 41;
    } else if (choose == 1) {
        throw "shit";
    } else if (choose == 2){
        IteratorOverflow ex(8, 2);
        throw ex;
    } else {
        throw 3.14f;
    }
}