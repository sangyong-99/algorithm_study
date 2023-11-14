//
//  명예의 전당 (1).cpp
//  algorithm_study
//
//  Created by 신상용 on 11/14/23.
//

#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> rank;
    for(int i = 0; i < score.size(); i++){
        if(i < k) rank.push(score[i]);
        else{
            if(rank.top() <= score[i]){
                rank.pop();
                rank.push(score[i]);
            }
        }
        answer.push_back(rank.top());
    }
}

int main() {
    int k = 9;
    vector<int> score = {10, 100, 20, 150, 1, 100, 200};
    solution(k, score);
}
