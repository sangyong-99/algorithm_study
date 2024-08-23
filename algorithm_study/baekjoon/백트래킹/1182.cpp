//
//  1182.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/24/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, M, S, temp, result;
vector<int> datas;
int arr[25];

void input_data() {
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        datas.push_back(temp);
    }
}

void func(int num, int k) {
    if (k == M) {
        temp = accumulate(arr, arr + M, 0);
        if (temp == S) {result++;}
        return;
    }
    
    for(int i = num; i < N; i++) {
        arr[k] = datas[i];
        func(i + 1, k + 1);
    }
    
}

int main() {
    input_data();
    for(int i = 1; i <= N; i++) {
        M = i;
        func(0, 0);
    }
    cout << result;
}
