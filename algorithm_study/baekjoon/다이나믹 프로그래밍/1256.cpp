//
//  1256.cpp
//  baekjoon
//
//  Created by 신상용 on 2023/01/11.
//

#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int dp[101][101] = {0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= 100; i++) {
        dp[i][0] = 1; dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (dp[i][j] > 1'000'000'000) dp[i][j] = 1'000'000'000;
        }
    }
    if (dp[n][m] < k) {
        cout << -1; return 0 ;
    }
    int a_cnt = n;
    int z_cnt = m;
    for (int i = 0; i < n + m; i++) {
        int as = dp[a_cnt - 1][z_cnt];
        
        if (a_cnt == 0) {
            cout << 'z';
            z_cnt--;
        }
        else if (z_cnt == 0) {
            cout << 'a';
            a_cnt--;
        }
        else if (k <= as) {
            cout << 'a';
            a_cnt--;
        }
        else {
            k = k - as;
            cout << 'z';
            z_cnt--;
        }
    }

    return 0;
}
