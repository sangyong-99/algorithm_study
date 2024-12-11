//
//  11727.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/11/24.
//

#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1010];

void input_data() {
    cin >> n;
}

void solution() {
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2 % 10007;
    }
    cout << dp[n] % 10007;
}

int main() {
    input_data();
    solution();
}
