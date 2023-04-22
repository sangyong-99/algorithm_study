//
//  같은 숫자는 싫어.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/22.
//

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    stack<int> left_stack;
    stack<int> right_stack;
    left_stack.push(arr[0]);
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] != left_stack.top()){
            left_stack.push(arr[i]);
        }
    }
    int sizess = left_stack.size();
    for(int i = 0; i < sizess; i++){
        right_stack.push(left_stack.top());
        left_stack.pop();
    }

    for(int i = 0; i < sizess; i++){
        answer.push_back(right_stack.top());
        right_stack.pop();
    }
    return answer;
}
