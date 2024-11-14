//
//  1225.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/14/24.
//

#include<bits/stdc++.h>

using namespace std;

int temp;
bool stan = true;
deque<int> vv;

void input() {
    cin >> temp;
    for (int i = 0; i < 8; i++) {
        cin >> temp;
        vv.push_back(temp);
    }
}

void clear() {
    vv.clear();
    stan = true;
}

int main(int argc, char **argv) {
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case) {
        clear();
        input();
        while (stan) {
            temp = 1;
            for (int i = temp; i < 6; i++) {
                temp = vv.front();
                vv.pop_front();
                temp -= i;
                if (temp <= 0) {
                    temp = 0;
                    vv.push_back(temp);
                    stan = false;
                    break;
                } else {
                    vv.push_back(temp);
                }

            }
        }
        cout << "#" << test_case << " ";
        for(int i = 0; i < 8; i++) {
            cout << vv[i] << " ";
        }
        cout << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
