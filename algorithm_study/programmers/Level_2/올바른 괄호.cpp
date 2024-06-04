//
//  올바른 괄호.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 6/4/24.
//

#include<string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> ss;
    for(char c: s) {
        if (c == '(') {
            ss.push('(');
            continue;
        }
        else if (c == ')') {
            if (!ss.empty()) {
                ss.pop();
            } else {
                return false;
            }
        }
    }
    
    if (!ss.empty()) {
        return false;
    }
    


    return answer;
}
