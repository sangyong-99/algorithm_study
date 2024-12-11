//
//  1932.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/11/24.
//

#include <bits/stdc++.h>

using namespace std;

int n, temp, results;
int datas[510][510];
int dp[510][510];
int dx[2] = {-1, 0};

void input_data() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> temp;
            datas[i][j] = temp;
        }
    }
}

void solution() {
    dp[1][1] = datas[1][1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int a = 0;
            for(int z = 0; z < 2; z++) {
                int nx = j + dx[z];
                if (nx < 1 || nx > n) continue;
                a = max(dp[i - 1][nx] + datas[i][j], a);
            }
            dp[i][j] = a;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input_data();
    solution();
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= i; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    for(int i = 1; i <= n; i++) {
        results = max(results, dp[n][i]);
    }
    cout << results;
}
