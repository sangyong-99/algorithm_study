//
//  프로세스.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/10/24.
//

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> qu;
    priority_queue<int> pq;
    for(int i = 0; i < priorities.size(); i++) {
        qu.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    while(!pq.empty()) {
        if (qu.front().first == pq.top()) {
            if (qu.front().second == location) return answer+1;
            pq.pop(); qu.pop();
            answer++;
        }
        else {
            pair<int, int> temp;
            qu.push(qu.front());
            qu.pop();
        }
    }
    return answer;
}
