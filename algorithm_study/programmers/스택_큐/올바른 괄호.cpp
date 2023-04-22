//
//  올바른 괄호.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/22.
//

#include<string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> char_stack;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            char_stack.push(')');
        }
        else {
            if(!char_stack.empty()){
                char_stack.pop();
            }
            else{
                answer = false;
                return answer;
            }
        }
    }
    if(!char_stack.empty()){
        answer = false;
        return answer;
    }
    answer = true;
    return answer;
}
