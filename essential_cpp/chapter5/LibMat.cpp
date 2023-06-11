//
// Created by hq on 2023/6/11.
//

#include "LibMat.h"
void print(const LibMat& mat);

void TestPrint() {
    LibMat libmat;
    print(libmat);
    cout << "------------------------------------"<< endl;

    Book b("foo", "bar");
    print(b);
    cout << "------------------------------------"<< endl;

    AudioBook a("foo", "bar", "shit");
    print(a);
    cout << "------------------------------------"<< endl;
}

void print(const LibMat& mat) {
    mat.print();

}