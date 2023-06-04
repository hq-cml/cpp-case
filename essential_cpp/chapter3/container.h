//
// Created by hq on 2023/6/4.
//
#include <iostream>
using namespace std;

#ifndef CHAPTER3_CONTAINER_H
#define CHAPTER3_CONTAINER_H

void Init();
void InsertDel();

template<typename ItType>
void Display(ItType first, ItType last) {
    for (ItType iter=first; iter!=last; iter++) {
        cout << *iter<<" ";
    }
    cout << endl;
}
#endif //CHAPTER3_CONTAINER_H
