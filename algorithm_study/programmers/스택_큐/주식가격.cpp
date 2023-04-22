//
//  주식가격.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/22.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>



using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int answers[100000];
    stack<int> index_stack;
    int tops = 0;
    for(int i = 0; i < prices.size(); i++){
        
        while ((!index_stack.empty()) && (prices[index_stack.top()] > prices[i])) {
            tops = index_stack.top();
            index_stack.pop();
            answers[tops] = i - tops;
        }
        index_stack.push(i);
    }

    
    while(!index_stack.empty()) {
        tops = index_stack.top();
        index_stack.pop();
        answers[tops] = prices.size() - tops - 1;
    }
    
    for(int i = 0; i < prices.size(); i++){
        tops = answers[i];
        answer.push_back(tops);
    }
    
    
    return answer;
}
