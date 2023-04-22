//
//  1699.cpp
//  Test
//
//  Created by 신상용 on 2022/11/22.
//

#include <bits/stdc++.h>
using namespace std;

int N, dp[120000];

int main(){
    cin >> N;
    dp[0] = 0; dp[1] = 1;
    for(int i = 1; i <= N; i++){
        dp[i] = i;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[N];
}
