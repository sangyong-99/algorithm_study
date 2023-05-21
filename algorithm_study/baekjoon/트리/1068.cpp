//
//  1068.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/21.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> v[50];
int N;
int cnt;
int dnode, rootidx;
bool visited[50];

void input_data(){
    rootidx = -1;
    cin >> N;
    for(int i = 0; i < N; i++){
        int pa;
        cin >> pa;
        if (pa == -1)
            rootidx = i;
        else {
            v[pa].push_back(i);
        }
    }
    cin >> dnode;
}

void dfs(int curnode){
    if (visited[curnode])
        return;
    visited[curnode] = true;
    if (v[curnode].size() == 0 || (v[curnode].size() == 1 && v[curnode][0] == dnode)){
        cnt++;
    }
    for (int i = 0; i < v[curnode].size(); i++){
        if (v[curnode][i] != dnode)
            dfs(v[curnode][i]);
    }
}

int main(){
    input_data();
    if (dnode == rootidx){
        cout << 0;
        return 0;
    }
    dfs(rootidx);
    cout << cnt;
    return 0;
}
