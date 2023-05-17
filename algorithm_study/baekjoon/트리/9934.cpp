//
//  9934.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/17.
//

#include <bits/stdc++.h>
using namespace std;

int k, num, arr[1050];
vector<int> tree[10];

void solution1(int s, int e, int d){
    if (d >= k) return;
    if (s == e){
        tree[d].push_back(arr[s]);
        return;
    }
    int m = (s + e) / 2;
    if (m < 0 || m >= num) return;
    tree[d].push_back(arr[m]);
    solution1(s, m - 1, d + 1);
    solution1(m + 1, e, d + 1);
}

void input_data(){
    cin >> k;
    num = pow(2, k) - 1;
    for (int i = 0; i < num; i++){
        cin >> arr[i];
    }
}

int main(){
    input_data();
    solution1(0, num - 1, 0);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < tree[i].size(); j++){
            cout << tree[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
