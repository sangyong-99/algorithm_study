//
//  1289.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/13/24.
//

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
    int test_case;
    int T;
    string s;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> s;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                result++;
                for (int j = i; j < s.size(); j++) {
                    (s[j] == '0') ? s[j] = '1' : s[j] = '0';
                }
            }
        }
        cout << "#" << test_case << " " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
