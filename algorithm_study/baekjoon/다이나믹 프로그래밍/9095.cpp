//
//  9095.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/9/24.
//

#include <bits/stdc++.h>
using namespace std;

int T, n, datas[15];

void solution() {
    datas[0] = 1;
    for(int i = 1; i < 12; i++) {
        int counts = 0;
        for(int j = 1; j <= 3; j++) {
            if ((i - j) < 0) continue;
            counts += datas[i - j];
        }
        datas[i] = counts;
    }
}

int main() {
    cin >> T;
    solution();
    for(int i = 0; i < T; i++) {
        cin >> n;
        cout << datas[n] << '\n';
    }
}
