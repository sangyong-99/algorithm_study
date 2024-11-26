//
//  1003.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/26/24.
//

#include <bits/stdc++.h>

using namespace std;

int T, N;
int dp[3][42];

void bottomToTop() {
    dp[1][0] = dp[2][1] = 1;
    dp[2][0] = dp[1][1] = 0;
    for (int i = 2; i <= 40; i++) {
        dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
        dp[2][i] = dp[2][i - 1] + dp[2][i - 2];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    bottomToTop();
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << dp[1][N] << " " << dp[2][N] << '\n';
    }
}
