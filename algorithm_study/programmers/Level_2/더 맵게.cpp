//
//  더 맵게.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 9/23/24.
//

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i: scoville) {
        pq.push(i);
    }
    
    //pq 프로그램 시작 후 바로 되면
    if (pq.top() >= K) {return answer;}
    
    
    while(pq.size() != 1){
        answer++;
        int temp = pq.top(); pq.pop();
        temp += (pq.top() * 2); pq.pop();
        pq.push(temp);
        if (pq.top() >= K) {return answer;}
        
        
    }
    return -1;
}

  
