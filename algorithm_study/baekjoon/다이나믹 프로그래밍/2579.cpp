//
//  2579.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/10/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, datas[310][3];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> datas[i][0];
    }
    
    datas[1][1] = datas[1][0];
    datas[2][1] = datas[1][1] + datas[2][0];
    datas[2][2] = datas[2][0];
    
    for(int i = 3; i <= N; i++) {
        datas[i][1] = datas[i-1][2] + datas[i][0];
        datas[i][2] = max(datas[i-2][1], datas[i-2][2]) + datas[i][0];
    }
    
    cout << max(datas[N][1], datas[N][2]);
}

d
