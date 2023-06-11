//
// Created by hq on 2023/6/11.
//

#ifndef CHAPTER5_LIBMAT_H
#define CHAPTER5_LIBMAT_H

#include <iostream>
using namespace std;

void TestPrint();

class LibMat {
public:
    LibMat(){
        cout<< "LibMat::LibMat() default constructor!" <<endl;
    }

    virtual ~LibMat() {
        cout<< "LibMat::~LibMat() destructor!" <<endl;
    }

    virtual void print() const {
        cout << "LibMat::print() -- I am a LibMat object!"<< endl;
    }
};

// Note: 继承关系
//       1. 继承关系有三种，public，protected，private，目前只讨论public继承
//       2. 子类构造函数的调用顺序--会先调用父类构造函数（析构函数调用顺序正相反）
//       3. virtual虚函数的覆盖，是多态的前提，virtual关键字是必需的！
//       4. 父类的指针和引用，都可以引发多态的机制
class Book:public LibMat {
public:
    Book(const string &title, const string &author):_title(title), _author(author) {
        cout << "Book::Book (" << title << ", "<<author <<") constructor!"<<endl;
    }

    virtual ~Book() {
        cout << "Book::~Book() destructor!"<<endl;
    }

    // Note：虚函数，这个关键字是必须的，否则无法实现多态（这一点和Java不同，Java中只要覆盖就可以）
    virtual void print() const {
        cout << "Book::print() -- I am a Book object! (" << _title << ", "<<_author <<")"<<endl;
    }

    const string &title() const {
        return _title;
    }
    const string &author() const {
        return _author;
    }
protected:
    // Note: protected成员
    //      1.可以被子类继承并访问的成员
    //      2.其他地方不可访问
    string _title;
    string _author;
};

// Note: 子类继续派生子类
class AudioBook: public Book {
public:
    AudioBook(const string &title, const string &author, const string &isbn):
    Book(title, author), _isbn(isbn) { // Note: 初始化器直接调用了父类的构造
        cout << "AudioBook::AudioBook (" << title << ", "<<author << "," << _isbn << ") constructor!"<<endl;
    }

    virtual ~AudioBook() {
        cout << "AudioBook::~AudioBook() destructor!"<<endl;
    }

    // Note: 对于父类的_title和_author，直接使用无区别
    virtual void print() const {
        cout << "AudioBook::print() -- I am a AudioBook object! (" << _title << ", "<<_author << "," << _isbn <<")"<<endl;
    }

protected:
    // Note: 父类里面的两个成员，也默认继承了，这里不需要写
    string _isbn;
};

#endif //CHAPTER5_LIBMAT_H
