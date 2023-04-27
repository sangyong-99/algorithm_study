//
//  1966.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/23.
//

#include <bits/stdc++.h>
using namespace std;
int testcase, N, M, buffer, maxss[110];
queue<pair<int, int>> qu;

void input_data(){
    for(int i = 0; i < 108; i++){
        maxss[i] = 0;
    }
    while(!qu.empty())   qu.pop();

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> buffer;
        maxss[i] = buffer;
        qu.push(make_pair(i, buffer));
    }
    sort(maxss, maxss+103, greater<>());
 
}

int main(){
    cin >> testcase;
    
    for(int j = 0; j < testcase; j++){
        input_data();
        
        for(int i = 0; ;){
            if(qu.front().second < maxss[i]){
                qu.push(make_pair(qu.front().first, qu.front().second));
                qu.pop();
            }
            
            
            else {          //(qu.front().second == maxss[i]);
                if(qu.front().first == M){
                    cout << i + 1 << '\n';
                    break;
                }
                else {
                    qu.pop();
                    i++;
                }
            }
            
        }
            
    }
}
