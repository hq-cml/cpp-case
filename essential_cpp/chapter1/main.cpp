#include <iostream>
//#include <string>
using namespace std;

void Temp() {
    string word;
    int min = 4;
    while(cin>>word) {
        if (word.size() < min) {
            continue;
        } else {
            cout <<word<<endl;
        }
    }
    // Note: C++风格的变量初始化--Constructor syntax
    //       这种风格更加Cpp，相对于C风格的赋值初始化
    //       好处是便于支持多值对象和模板对象的初始化
    int num_tries(0); // 用户猜过得总次数

    double user_score = 0.0;
    char user_rsp;
    cout<<"Try another times? Y/N ";
    cin>>user_rsp;
    const int max_tries = 3;
    // max_tries = 4; 编译报错，常量不可改变


    bool next_seq = true; // 显示下一组数列
    bool go_for_it = true; // 是否希望再猜一次
    bool got_it = true; // 是否猜对
    int num_right = 0; // 猜对总次数
    int next_elem;


    while(next_seq) {
        // TODO 显示队列，猜测
        while (!got_it && go_for_it) {
            int user_guess;
            cin >> user_guess;
            num_tries++;
            if (user_guess == next_elem) {
                got_it = true;
                num_right++;
            } else {
                // 猜错
                if(user_rsp == 'N' || user_rsp=='n') {
                    go_for_it = false;
                }
            }
        }

        cout <<"Want to try another sequence? (Y/N)";
        char try_again;
        cin>>try_again;
        if (try_again == 'N' || try_again == 'n') {
            next_seq = false;
        }
    }
}


// 最简单的IO
void First() {
    string user_name;
    cout << "Please input name:" << endl;
    cin>>user_name;
    cout<<endl;
    cout<<"Hello "<<user_name<<". Bye Bye!\n";
}

int main() {
    Temp();
    //First();
    return 0;
}
