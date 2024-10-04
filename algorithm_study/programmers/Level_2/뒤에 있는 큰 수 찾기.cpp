//
//  뒤에 있는 큰 수 찾기.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 10/5/24.
//

#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> ss;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    
    for(int i = 0; i < numbers.size(); i++) {
        while(!ss.empty()) {
            auto ssTop = ss.top();
            if (numbers[i] > ssTop.second) {
                answer[ssTop.first] = numbers[i];
                ss.pop();
            } else break;
        }
        ss.push({i, numbers[i]});
    }
    
    while(!ss.empty()) {
        auto ssTop = ss.top();
        answer[ssTop.first] = -1;
        ss.pop();
    }
    
    return answer;
}
