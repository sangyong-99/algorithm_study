//
//  15650(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 8/22/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int num, int k){
    if (k == M) {
        for(int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(i+1, k+1);
            isused[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    func(1, 0);
}
