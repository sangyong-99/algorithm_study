//
//  2817.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/13/24.
//

#include<bits/stdc++.h>
using namespace std;

int N, K, result, temp;
int data[25];

void input_data() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> data[i];
    }
}

void dfs(int index) {
    for(int i = index; i < N; i++) {
        temp += data[i];
        if (temp == K) {
            result++;
        }
        dfs(i + 1);
        temp -= data[i];
    }
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        input_data();
        temp = 0;
        result = 0;
        dfs(0);

        cout << "#" << test_case << " " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
