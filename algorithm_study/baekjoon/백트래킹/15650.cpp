//
//  15650.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/22/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int k){
    if (k == M) {
        for(int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int standard;
    if (k == 0) {standard = 1;}
    else {standard = arr[k - 1];}
    for(int i = standard; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    func(0);
}
