//
//  1220.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/13/24.
//

#include <bits/stdc++.h>

using namespace std;

int datas[110][110];
int len, temp, result;

void input_data() {
    cin >> len;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cin >> temp;
            datas[i][j] = temp;
        }
    }
}

int main(int argc, char **argv) {
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case) {
        input_data();
        result = 0;

        for(int i = 0; i < 100; i++) {
            int flag = 0;
            for(int j = 0; j < 100; j++) {
                int temp = datas[j][i];
                if (temp == 1) {
                    flag = 1;
                } else if(temp == 2) {
                    if (flag == 1) {
                        result++;
                    }
                    flag = 2;
                }
            }
        }
        cout <<"#" << test_case << " " <<  result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
