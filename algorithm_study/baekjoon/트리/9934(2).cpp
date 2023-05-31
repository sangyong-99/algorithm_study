//
//  9934(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/30.
//

#include <bits/stdc++.h>
using namespace std;

int K, num, arr[1100];
vector<int> results[12];

void solution1(int st, int en, int re){
    if (st + 1 == en) {
        results[re].push_back(arr[st]);
        return;
    }
    int num2 = (st + en) / 2;
    results[re].push_back(arr[num2]);
    re++;
    solution1(st, num2, re);
    solution1(num2 + 1, en, re);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> K;
    num = pow(2, K) - 1;
    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }
    solution1(0, num, 0);
    for(int i = 0; i < K; i++){
        for(int j = 0; j < results[i].size(); j++){
            cout << results[i][j] << " ";
        }
        cout << "\n";
    }
}
