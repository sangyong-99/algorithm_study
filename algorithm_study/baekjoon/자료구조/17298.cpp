//
//  17298.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/03.
//

#include <bits/stdc++.h>
using namespace std;

int N, buffer;
int A[1000000];
int results[1000000];
stack<pair<int, int>> stackss;

void input_data(){
    cin >> N;
    
}

int main(){
    input_data();
    cin >> buffer;
    stackss.push(make_pair(0, buffer));
    for(int i = 1; i < N; i++){
        cin >> buffer;
        while(!stackss.empty()){
            if(buffer > stackss.top().second){
                results[stackss.top().first] = buffer;
                stackss.pop();
            }
            else break;
        }
        stackss.push(make_pair(i, buffer));
    }
    for(int i = 0; i < N; i++){
        if(results[i] == 0){
            results[i] = -1;
        }
    }
    for(int i = 0; i < N; i++){
        cout << results[i] << " ";
    }
}
