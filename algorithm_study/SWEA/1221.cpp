//
//  1221.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/16/24.
//

#include<bits/stdc++.h>

using namespace std;

map<string, int> mm;
string str;
int len, st;
string datas[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int main(int argc, char **argv) {
    int test_case;
    int T;
    freopen("../GNS_test_input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        mm.clear();
        cin >> str;
        st = stoi(str.substr(1));
        cin >> len;
        for(int i = 0; i < len; i++) {
            cin >> str;
            mm[str]++;
        }

        cout << "#" << st << '\n';
        for(int i = 0; i < 10; i++) {
            int countss = mm[datas[i]];
            for(int j = 0; j < countss; j++) {
                cout << datas[i] << " ";
            }
            cout << '\n';
        }

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
