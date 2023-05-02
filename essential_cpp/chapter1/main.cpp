#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Note: C++中输入流可以作为boo条件，有效流返回true
//      如果无效流（遇到文件结束符ctrl+z，或者ctrl+d）返回false
void Other1() {
    string word;
    int min = 4;
    while(cin>>word) {
        if (word.size() < min) {
            continue;
        } else {
            cout <<word<<endl;
        }
    }
}

// 数列猜测，有以下六种数列：
// Fibonacci:  1,1,2,3,5,8,13...
// Lucas:      1,3,4,7,11,18...
// Pell:       1,2,5,12,29,70...
// Triangular: 1,3,6,10,15,21...
// Square:     1,4,9,16,25,36...
// Pentagonal: 1,5,12,22,35,51...
// 需求：
// 给定每个数列的第2,3项，猜测第4项，并且根据用户的选择是否继续
void GuessNumber() {
    // Note: C++风格的变量初始化--Constructor syntax
    //       这种风格更加Cpp，相对于C风格的赋值初始化
    //       好处是便于支持多值对象和模板对象的初始化
    int num_tries(0); // 用户猜过得总次数
    double user_score = 0.0;
    const int max_tries = 3;
    // max_tries = 4; 编译报错，常量不可改变

    bool next_seq = true;  // 显示下一组数列
    bool go_for_it = true; // 是否希望再猜一次
    bool gotIt = false;    // 是否猜对
    int num_right = 0;     // 猜对总次数
    int next_elem;

    // 定义6种数列的第2,3,4项，组成一个序列
    const int seqSize = 18;      // 常量长度
    //int arrSeq[seqSize];         // Note: 数组形式定义
    //vector<int> vecSeq[seqSize]; // Note: Vector形式定义
    int arrSeq[seqSize] = {        // Note: 数组形式定义并直接初始化
        1,2,3,      // Fibonacci
        3,4,7,      // Lucas
        2,5,12,     // Pell
        3,6,10,     // Triangular
        4,9,16,     // Square
        5,12,22     //
    };
    // Note: Vector形式定义并直接初始化（依赖于一个数组，且参数是头尾指针）
    vector<int> vecSeq(arrSeq, arrSeq+seqSize);

    // 数列名字
    string arrNames[6] = {
            "Fibonacci",
            "Lucas",
            "Pell",
            "Triangular",
            "Square",
            "Pentagonal",
    };

    int currIdx = 0;
    while(next_seq && currIdx < seqSize) {
        // 显示队列，进行猜测
        cout << "The first two elem of the sequence are: "
        << vecSeq[currIdx] << ", "      // Note: Vector的元素读取方式和数组一样
        << vecSeq[currIdx+1] << endl;
        next_elem = vecSeq[currIdx+2];
        go_for_it = true;
        while (!gotIt && go_for_it) {
            cout << "What is the next? ";
            int user_guess;
            cin >> user_guess;
            num_tries++;
            if (user_guess == next_elem) {
                gotIt = true;                         // 猜对
                num_right++;
                cout << "Good! "<< next_elem << " is the next elem"
                << "in the "<<arrNames[currIdx/3]<< " Sequence."<< endl;
            } else {
                gotIt = false;                       // 猜错
                char rsp;
                cout<<"Wrong!! Try another times? (Y/N) ";
                cin>>rsp;
                if(rsp == 'N' || rsp=='n') {
                    go_for_it = false;
                }
            }
        }

        cout <<"Want to try another sequence? (Y/N) ";
        char t;
        cin>>t;
        if (t == 'N' || t == 'n') {
            next_seq = false;
        } else {
            currIdx += 3;
            gotIt = false;
        }
    }
}

int main() {
    GuessNumber();
    //Other1();
    //First();
    return 0;
}

// 最简单的IO
void First() {
    string user_name;
    cout << "Please input name:" << endl;
    cin>>user_name;
    cout<<endl;
    cout<<"Hello "<<user_name<<". Bye Bye!\n";
}
