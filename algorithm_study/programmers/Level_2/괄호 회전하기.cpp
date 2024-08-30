//
//  괄호 회전하기.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/30/24.
//

#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> datas;
    
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
            datas.push(s[i]);
            continue;
        }
        if (datas.empty()) {return false;}
        switch (s[i]) {
            case ')':
                if (datas.top() == '(') {datas.pop();}
                else {return false;}
                break;
            case ']':
                if (datas.top() == '[') {datas.pop();}
                else {return false;}
                break;
            case '}':
                if (datas.top() == '{') {datas.pop();}
                else {return false;}
                break;
        }
    }
    if (datas.empty()) {return true;}
    return false;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if (check(s)) answer++;
        s += s[0];
        s.erase(0, 1);
    }
    
    return answer;
}

int main() {
    cout << solution("[](){}");
}
