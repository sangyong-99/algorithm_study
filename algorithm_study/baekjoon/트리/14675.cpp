//
//  14675.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/17.
//

#include <bits/stdc++.h>
using namespace std;

int N, a, b, q, t, k;
bool results = false;
vector<int> tree[100005];
vector<pair<int, int>> tree_copy;
bool visited[100005] = {false, };

void input_data(){
    cin >> N;
    for (int i = 0; i < N - 1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        tree_copy.push_back(make_pair(a, b));
    }
}

void dfs1(int number){
    visited[number] = true;
    for(int i = 0; i < tree[number].size(); i++){
        int arrayinnumber = tree[number][i];
        if (!visited[arrayinnumber] && arrayinnumber != k){
            dfs1(arrayinnumber);
        }
    }
}

void dfs2(int number){
    visited[number] = true;
    for(int i = 0; i < tree[number].size(); i++){
        int arrayinnumber = tree[number][i];
        if((tree_copy[k - 1].first == number && tree_copy[k - 1].second == arrayinnumber) || (tree_copy[k - 1].first == arrayinnumber && tree_copy[k - 1].second == number)){
            continue;
        }
        if (!visited[arrayinnumber]){
            dfs2(arrayinnumber);
        }
    }
}

void reset_data(){
    for(int i = 0; i <= 100002; i++){
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input_data();
    cin >> q;
    for(int i = 0 ; i < q; i++){
        cin >> t >> k;
        reset_data();
        if (t == 1){
            if (k == 1){
                dfs1(2);
            }
            else {
                dfs1(k - 1);
            }
            //dfs1
            results = false;
            for(int j = 1; j <= N; j++){
                if (j != k){
                    if(!visited[j]){
                        results = true;
                    }
                }
            }
            if( results){
                cout << "yes" << "\n";
            }
            else{
                cout << "no" << "\n";
            }
        }
        else if (t == 2){
            dfs2(1);
            //dfs2
            results = false;
            for(int j = 1; j <= N; j++){
                if(!visited[j]){
                    results = true;
                }
            }
            if( results){
                cout << "yes" << "\n";
            }
            else{
                cout << "no" << "\n";
            }
        }
    }
    
}
