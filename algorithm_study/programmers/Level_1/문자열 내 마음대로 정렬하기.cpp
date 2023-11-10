//
//  문자열 내 마음대로 정렬하기.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/10/23.
//

#include <bits/stdc++.h>

using namespace std;
int nn = 0;

bool compare(string a, string b) {
    return a[nn] == b[nn] ? a < b : a.substr(nn) < b.substr(nn);
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    nn = n;
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}
