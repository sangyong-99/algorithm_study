//
//  20924.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/30.
//

#include <bits/stdc++.h>
using namespace std;

int N, R, a, b, d;
bool tree_visited[200010] = {false, };
//int datas_arr[200010][3];
vector<pair<int, int>> tree_v[200010];
int giganode = -1;
int treeglen = 0;
int treegagilen = 0;
int maxss = 0;

void solution1(int num){
    
    giganode = num;     //기가노드 체크리스트 찍어줌
    tree_visited[num] = true;
    if (num == R){      //num이 첫 노드면 사이즈가 1이여야함. 아니면
        if (tree_v[num].size() == 1){
            treeglen += tree_v[num][0].second;
            solution1(tree_v[num][0].first);
        } else {
            return ;
        }
    } else {
        if (tree_v[num].size() == 2){
            for(int i = 0; i < 2; i++){
                if(!tree_visited[tree_v[num][i].first]){
                    treeglen += tree_v[num][i].second;
                    solution1(tree_v[num][i].first);
                }
            }
        } else {
            return ;
        }
    }
}


void solution2(int num, int re){
    tree_visited[num] = true;
    
    if (tree_v[num].size() == 1){
        if(maxss < treegagilen) {
            maxss = treegagilen;
        }
        treegagilen -= re;
        return ;
    }
    for(int i = 0; i < tree_v[num].size(); i++){
        if (!tree_visited[tree_v[num][i].first]){
            treegagilen += tree_v[num][i].second;
            solution2(tree_v[num][i].first, tree_v[num][i].second);
        }
    }
    treegagilen -= re;
}


int main(){
    cin >> N >> R;
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b >> d;
        tree_v[a].push_back(make_pair(b, d));
        tree_v[b].push_back(make_pair(a, d));
    }
    giganode = R;
    solution1(R);
    
    solution2(giganode, 0);
    
    cout << treeglen << " " << maxss;
    
}
