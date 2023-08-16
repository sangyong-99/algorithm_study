//
//  11053(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/08/16.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int N; int data_arr[1000010];
int temp;

void input_data() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        data_arr[i] = temp;
    }
}

int main() {
    input_data();
    dp.push_back(data_arr[0]);
    for(int i = 1; i < N; i++) {
        if (data_arr[i] > dp[dp.size() - 1]) {
            dp.push_back(data_arr[i]);
        } else {
            for(int j = 0; j <= dp.size() - 1; j++) {
                if (data_arr[i] == dp[j]) break;
                if (data_arr[i] < dp[j]) {
                    dp[j] = data_arr[i];
                    break;
                }
            }
        }
        
    }
    cout << dp.size();
}
