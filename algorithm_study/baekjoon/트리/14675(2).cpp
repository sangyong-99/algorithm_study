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

void input_data(){
    cin >> N;
    for (int i = 0; i < N - 1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input_data();
    cin >> q;
    for(int i = 0 ; i < q; i++){
        cin >> t >> k;
        if (t == 1){
            if (tree[k].size() > 1){
                cout << "yes" << '\n';
            }
            else {
                cout << "no" << '\n';
            }
        }
        else if (t == 2){
                cout << "yes" << "\n";
        }
    }
    
}
