//
//  15663.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/23/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, M, temp;
vector<int> datas;
int arr[10], used[10];

void input_data() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        datas.push_back(temp);
    }
    sort(datas.begin(), datas.end());
}

void func(int k) {
    if (k == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int standard = 0;
    for(int i = 0; i < N; i++) {
        if (standard != datas[i]) {
            if (!used[i]){
                standard = datas[i];
                arr[k] = datas[i];
                used[i] = true;
                func(k+1);
                used[i] = false;
            }
        }
    }
}

int main() {
    input_data();
    func(0);
}
