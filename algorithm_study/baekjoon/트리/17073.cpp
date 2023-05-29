//
//  17073.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/29.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> datas[500009];
int n, w, u, v, countss;

void input_data(){
    cin >> n >> w;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        datas[u].push_back(v);
        datas[v].push_back(u);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input_data();
    for(int i = 2; i <= n; i++){
        if (datas[i].size() == 1){
            countss++;
        }
    }
    cout.precision(15);
    cout << (double)w / countss;
}
