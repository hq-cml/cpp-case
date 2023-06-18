//
// Created by hq on 2023/6/18.
//

#include "member_template.h"

void TestMemberTemplate() {
    PrintIt toStdOut(cout);
    toStdOut.print(1);
    toStdOut.print("Hello");
    string s("world");
    toStdOut.print(s);
    cout << endl;
    PrintItV2<ostream> toStdOut2(cout);
    toStdOut2.print(1);
    toStdOut2.print("Hello");
    string s2("world");
    toStdOut2.print(s2);
}