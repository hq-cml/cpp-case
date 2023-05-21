#include <iostream>
using namespace std;

// Note: 函数的声明，让编译器知道begin函数的存在。
void begin();

int main() {
    begin();
    return 0;
}

// 斐波那契数列: 0, 1, 1, 2, 3( pos从0开始计数）
// Note: 利用引用参数作为返回值
bool fibon_elem(int pos, int &elem) {
    if (pos <=0 || pos > 1024) {
        elem = 0;
        return false;
    }
    elem = 1;
    int n1 = 1, n2 = 1;
    for (int idx = 3; idx <= pos; idx ++) {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
    }
    return true;
}

void begin() {
    int pos;
    cout << "Please input a pos:";
    cin >> pos;

    int elem;
    if(fibon_elem(pos, elem)) {
        cout << "Elem #" << pos << " is " << elem <<endl;
    } else {
        cout << "Sorry. Invalid pos:"<<pos<<endl;
    }
}

