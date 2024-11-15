//
//  1213.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/15/24.
//

#include<iostream>

using namespace std;

int num, result;
int indexs = 0;
string f, str;

void input() {
    cin >> num;
    cin >> f >> str;
}

void solution() {
    while((indexs = str.find(f)) != string::npos) {
        result++;
        str.erase(0, indexs +2);
    }
}

int main(int argc, char** argv) {
    for(int test_case = 1; test_case <= 10; ++test_case) {
        input();
        solution();
        cout << "#" << num << " " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
