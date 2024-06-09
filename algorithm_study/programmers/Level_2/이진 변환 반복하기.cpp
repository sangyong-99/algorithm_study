//
//  이진 변환 반복하기.cpp
//  algorithm_study
//
//  Created by 신상용 on 6/9/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int recur_count = 0, remove_count = 0;
int total_remove_count;
string solution1(int remove_length) {
    vector<int> ii;
    string result = "";
    while(remove_length != 0) {
        ii.push_back(remove_length % 2);
        remove_length = remove_length / 2;
    }
    
    reverse(ii.begin(), ii.end());
    for(int i : ii) {
        result += i + '0';
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    while(s != "1") {
        recur_count++;
        int prev_count = s.length();
        remove_count = 0;
        for(char c: s) {
            if (c == '0') remove_count++;
        }
        total_remove_count += remove_count;
        int remove_length = prev_count - remove_count;
        
        s = solution1(remove_length);
    }
    answer.push_back(recur_count);
    answer.push_back(total_remove_count);
    return answer;
}
