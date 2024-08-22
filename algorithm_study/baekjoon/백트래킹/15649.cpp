//
//  15649.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/22/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int k) {
    if (k == M) {
        for(int i = 0; i < M; i++) cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);
}
