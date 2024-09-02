//
//  의상.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/2/24.
//

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for(vector<string> v: clothes) {
        m[v[1]]++;
    }
    
    for(auto it = m.begin(); it != m.end(); it++) {
        answer *= (it -> second + 1);
    }
    answer--;
    return answer ;
}
