//
//  1209.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/13/24.
//

#include<iostream>

using namespace std;

int datas[110][110];
int result, temp;

void input() {
    cin >> temp;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cin >> datas[i][j];
        }
    }
}

int main(int argc, char **argv) {
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case) {
        result = 0;
        input();
        for (int i = 0; i < 100; i++) {
            temp = 0;
            for (int j = 0; j < 100; j++) {
                temp += datas[i][j];
            }
            result = max(result, temp);
        }

        for (int i = 0; i < 100; i++) {
            temp = 0;
            for (int j = 0; j < 100; j++) {
                temp += datas[j][i];
            }
            result = max(result, temp);
        }

        temp = 0;
        for (int i = 0; i < 100; i++) {
            temp += datas[i][i];
        }
        result = max(result, temp);

        temp = 0;
        for (int i = 99; i >= 0; i--) {
            temp += datas[i][i];
        }
        result = max(result, temp);
        cout << "#" << test_case << " " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
