#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

// Note: C++中输入流可以作为循环结束条件，有效流返回true
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

// 函数声明
void guess (int next_elem, string seqName, int &num_tries, int &num_right);

// 引入指针，提升灵活性
// 引入随即数，提升趣味性
void GuessNumberV2() {
    int num_tries(0); // 用户猜过得总次数
    bool next_seq = true;  // 显示下一组数列
    //bool go_for_it = true; // 是否希望再猜一次
    //bool gotIt = false;    // 是否猜对
    int num_right = 0;     // 猜对总次数
    int next_elem;

    const int seqCnt = 6;
    // 定义6种数列的第2,3,4项，组成一个序列
    vector<int> Fibonacci = {1,2,3};
    vector<int> Lucas = {3,4,7};
    vector<int> Pell = {2,5,12};
    vector<int> Triangular = {3,6,10};
    vector<int> Square = {4,9,16};
    vector<int> Pentagonal = {5,12,22};
    vector<int> *seqAddrs[seqCnt] = {
            &Fibonacci, &Lucas, &Pell, &Triangular, &Square, &Pentagonal
    };

    // 数列名字
    string arrNames[seqCnt] = {
            "Fibonacci",
            "Lucas",
            "Pell",
            "Triangular",
            "Square",
            "Pentagonal",
    };

    int currIdx = 0;
    srand(seqCnt);
    while(next_seq) {
        int seqIdx = rand()%seqCnt;
        vector<int> *pv = seqAddrs[seqIdx];
        // 显示队列，进行猜测
        cout << "The first two elem of the sequence are: "
             << (*pv)[0] << ", "      // Note: Vector的元素读取方式和数组一样
             << (*pv)[1] << endl;
        next_elem = (*pv)[2];
        guess(next_elem,arrNames[seqIdx], num_tries, num_right);
        cout <<"Want to try another sequence? (Y/N) ";
        char t;
        cin>>t;
        if (t == 'N' || t == 'n') {
            next_seq = false;
        }
    }
}

void guess (int next_elem, string seqName, int &num_tries, int &num_right) {
    bool go_for_it = true; // 是否希望再猜一次
    bool gotIt = false;    // 是否猜对

    while (!gotIt && go_for_it) {
        cout << "What is the next? ";
        int user_guess;
        cin >> user_guess;
        num_tries++;
        if (user_guess == next_elem) {
            gotIt = true;                         // 猜对
            num_right++;
            cout << "Good! "<< next_elem << " is the next elem"
                 << "in the "<<seqName<< " Sequence."<< endl;
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
void GuessNumberV1() {
    // Note: C++风格的变量初始化--Constructor syntax
    //       这种风格更加Cpp，相对于C风格的赋值初始化
    //       好处是便于支持多值对象和模板对象的初始化
    int num_tries(0); // 用户猜过得总次数
    double user_score = 0.0;
    const int max_tries = 3;
    // max_tries = 4; 编译报错，常量不可改变

    bool next_seq = true;  // 显示下一组数列
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
        5,12,22     // Pentagonal
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
        guess(next_elem,arrNames[currIdx/3], num_tries, num_right);
        cout <<"Want to try another sequence? (Y/N) ";
        char t;
        cin>>t;
        if (t == 'N' || t == 'n') {
            next_seq = false;
        } else {
            currIdx += 3;
        }
    }
}

//文件的读
void ReadFile(string file) {
    ifstream inFile(file);
    if (!inFile) {
        cerr << "Open failed!"; // 比如文件不存在，就会走到这里
        return;
    }
    string line;
    int i = 0;
    while (inFile >> line) {
        cout << i++ << ": " << line << endl;
    }
}

// 文件的写
void WriteFile(string file, string content) {
    ofstream outFile(file, ios_base::app);
    if (!outFile) {
        cerr << "Open failed!"; // 比如文件不存在，就会走到这里
        return;
    }
    outFile << content;
}

// 文件读写，TODO 这个函数有问题，写总是失败。。。
void IOFile(string file, string content) {
    fstream ioFile(file, ios_base::in|ios_base::out);
    if (!ioFile) {
        cerr << "Open failed!"; // 比如文件不存在，就会走到这里
        return;
    }
    ioFile.seekg(0);
    string line;
    int i = 0;
    while (ioFile >> line) {
        cout << i++ << ": " << line << endl;
    }
    //ioFile.seekp(5);
    ioFile << content << endl;
}

int main() {
    IOFile("b.txt", "World");
    //WriteFile("b.txt", "Hello\n");
    //ReadFile("a.txt");
    //GuessNumberV2();
    //GuessNumberV1();
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
