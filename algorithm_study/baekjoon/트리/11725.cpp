//
//  11725.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/15.
//

#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<int> tree[100005];
int answer[100005];
bool visited[100005] = {false, };



void input_data(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

void dfs(int number){
    visited[number] = true;
    for(int i = 0; i < tree[number].size(); i++){
        int ccc = tree[number][i];
        if (!visited[ccc]){
            answer[ccc] = number;
            dfs(ccc);
        }
    }
}

int main(){
    input_data();
    dfs(1);
    for(int i = 2; i <= N; i++){
        cout << answer[i] << '\n';
    }
}
