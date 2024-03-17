//
//  String_division.cpp
//  algorithm_study
//
//  Created by 신상용 on 3/17/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

char temp;
int count1 = 0;
int count2 = 0;

int solution(string s) {
    int answer = 0;
    
    temp = s[0];
    count1 = 1;
    
    for(int i = 1; i < s.length(); i++) {
        if (s[i] == temp) {
            count1++;
        }
        else {
            count2++;
        }
        if (count1 == count2) {
            i++;
            temp = s[i];
            answer++;
            count1 = 1;
            count2 = 0;
        }
    }
    
    if (temp != NULL) {
        answer++;
    }
    return answer;
}
