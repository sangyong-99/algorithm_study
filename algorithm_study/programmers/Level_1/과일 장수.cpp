//
//  과일 장수.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 12/9/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    
    int recursionCount = score.size() / m;
    for(int i = 1; i <= recursionCount; i++) {
        int temp_score = *(score.begin() + (m*i-1));
        temp_score *= m;
        answer += temp_score;
    }
    
    //시간 초과 초드
//     while(m <= score.size()) {
//         int temp_score = *(score.begin() + (m - 1));
//         temp_score *= m;
//         answer += temp_score;
        //score 배열을 삭제하는 함수 때문에 오류남
//         score.erase(score.begin(), score.begin() + m);
//     }
    return answer;
}
