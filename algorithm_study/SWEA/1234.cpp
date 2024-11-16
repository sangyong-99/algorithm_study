//
//  1234.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/16/24.
//

#include<bits/stdc++.h>

using namespace std;

int N;
string str;
char temp;

int main(int argc, char **argv) {
    int test_case;
    int T = 10;
    freopen("../input.txt", "r", stdin);
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> str;

        while(true) {
            bool flag = false;
            char stan = str[0];
            for(int i = 1; i < str.length(); i++) {
                temp = str[i];
                if (stan == str[i]) {
                    str.erase(i - 1, 2);
                    flag = true;
                    break;
                }
                stan = temp;
            }
            if (!flag) break;
        }
        cout << "#" << test_case << " " << str << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
