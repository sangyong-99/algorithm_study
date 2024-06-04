//
//  JadenCase 문자열 만들기.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 6/4/24.
//

#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    bool bb = false;
    for(char cc: s) {
        if (cc == ' ') {
            bb = false;
            answer += cc;
            continue;
        }
        
        if (!bb) {      //bb = false;
            if (isdigit(cc)) {
                answer += cc;
                bb = true;
                continue;
            }
            else {
                answer += toupper(cc);
                bb = true;
                continue;
            }
        } else if (bb) {     //bb = true;
            answer += tolower(cc);
            bb = true;
            continue;
        }
    }
    
    return answer;
}
