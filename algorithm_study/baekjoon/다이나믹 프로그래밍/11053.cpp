//
//  11053.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/08/16.
//  동적 계획법을 활용한 풀이 : O(N^2)

#include <bits/stdc++.h>
using namespace std;

int N; int data_arr[1010], dp[1010];
int temp;
int result = 0;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        data_arr[i] = temp;
    }
    
    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            if (data_arr[j] < data_arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
            
    }
    
    for(int i = 0; i < N; i++) {
        if (result < dp[i]) {
            result = dp[i];
        }
    }
    cout << result;
}
