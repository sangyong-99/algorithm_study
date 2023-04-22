//
//  1010.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/12/22.
//

#include <bits/stdc++.h>
using namespace std;

int T, N, M, sum[35][35];

void input_data(){
    for(int i = 1; i < 35; i++){
        for(int j = i; j < 35; j++){
            if(i == j) sum[i][j] = 1;
            else if(i == 1) sum[i][j] = j;
            else{
                sum[i][j] = sum[i][j-1] + sum[i-1][j-1];
            }
        }
    }
}

int main(){
    cin >> T;
    input_data();
    for(int i = 0; i < T; i++){
        cin >> N >> M;
        cout << sum[N][M] << '\n';
    }
}
