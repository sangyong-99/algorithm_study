//
//  11659.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/26/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, temp, i, j;
int dp[100010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 2; i <= N + 1; i++) {
        cin >> temp;
        dp[i] = dp[i - 1] + temp;
    }

     for(int countss = 0; countss < M; countss++) {
        cin >> i >> j;
        cout << dp[j + 1] - dp[i] << '\n';
    }
}
