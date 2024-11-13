//
//  2805.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/12/24.
//

#include<bits/stdc++.h>
using namespace std;

int datas[51][51];
int N;
int result = 0;

void clear() {
    memset(datas, 0, sizeof(datas));
    result = 0;
}

void input() {
    cin >> N;
    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        for(int j = 0; j < N; j++) {
            datas[i][j] = temp[j] - '0';
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case) {
        clear();
        input();
        int temp = N / 2;
        int count = 1;
        int standard = -1;
        int countstan = 2;
        for(int i = 0; i < N; i++) {
            int ctemp = temp;
            for(int j = 0; j < count; j++) {
                result += datas[i][ctemp];
                ctemp++;
            }
            if (temp + standard < 0) {
                standard = 1;
                countstan = -2;
            }
            temp += standard;
            count += (countstan);
        }
        cout << "#" << test_case << " " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
