//
//  9465.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/26/24.
//

#include <bits/stdc++.h>

using namespace std;

int test_case, n;
int datas[3][100010];
int dp[3][100010];

void clear() {
    memset(dp, 0, sizeof(dp));
}

int main() {
    cin >> test_case;
    for (int i = 1; i <= test_case; i++) {
        cin >> n;
        for (int i = 1; i < 3; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> datas[i][j];
            }
        }

        dp[1][1] = datas[1][1];
        dp[2][1] = datas[2][1];

        for (int i = 2; i <= n; i++) {
            dp[1][i] = max({dp[1][i - 2], dp[2][i - 2], dp[2][i - 1]}) + datas[1][i];
            dp[2][i] = max({dp[1][i - 2], dp[2][i - 2], dp[1][i - 1]}) + datas[2][i];
        }

        cout << max(dp[1][n], dp[2][n]) << '\n';
    }
}
