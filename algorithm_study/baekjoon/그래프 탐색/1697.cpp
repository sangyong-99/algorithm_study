//
//  1697.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/8/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, K;
int x[3];
int datas[100100];
queue<int> queue_data;

void solution1() {
    queue_data.push(N);
    datas[N] = 0;
    while (!queue_data.empty()) {
        int temp = queue_data.front(); queue_data.pop();
        int counts = datas[temp];
        x[0] = temp - 1; x[1] = temp + 1; x[2] = temp * 2;
        for(int i = 0; i < 3; i++) {
            if (x[i] < 0 || x[i] > 100000 || datas[x[i]] != -1) continue;
            datas[x[i]] = counts + 1;
            if (x[i] == K) {return;}
            queue_data.push(x[i]);
        }
    }
}

int main() {
    fill_n(datas, 100100, -1);
    cin >> N >> K;
    if (N >= K) {cout << (N - K); return 0;}
    else solution1();
    cout << datas[K];
}
