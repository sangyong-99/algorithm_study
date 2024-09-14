//
//  피로도.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/14/24.
//

#include <bits/stdc++.h>
using namespace std;

bool used[10];
int he, arr[10];

void permutation( int depth, int k, int& answer, vector<vector<int>> dungeons) {
    int health = he;
    if (depth == k) {
        
        for(int i = 0; i < k; i++) {
            if (health >= dungeons[arr[i]][0]){
                health -= dungeons[arr[i]][1];
            } else {
                return;
            }
        }
        answer = k; return;
    }
    
    for(int i = 0; i < dungeons.size(); i++){
        if (!used[i]) {
            used[i] = true;
            arr[depth] = i;
            permutation(depth+1, k, answer, dungeons);
            used[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    he = k;
    for(int i = 1; i <= dungeons.size(); i++) {
        permutation(0, i, answer, dungeons);
    }
    cout << answer;
    return answer;
}

int main(){
    solution(80, {{80,20},{50,40},{30,10}});
    return 0;
}
