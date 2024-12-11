//
//  2193.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/11/24.
//

#include <bits/stdc++.h>

using namespace std;

long long dp[100][2];
int N;

void input_data() {
    cin >> N;
}

void solution() {
    dp[1][1] = 1;
    dp[1][0] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0];
    }
}

int main() {
    input_data();
    solution();
    cout << dp[N][0] + dp[N][1];
}
