//
//  [1차] 뉴스 클러스터링.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/14/24.
//

#include <bits/stdc++.h>

using namespace std;

void input_data(string str, unordered_map<string, int> &m) {
    for(int i = 0; i < str.size() - 1; i++) {
        if (isalpha(str[i]) && isalpha(str[i+1])){
            m[str.substr(i, 2)]++;
        }
    }
}

int solution(string str1, string str2) {
    double answer = 0, inter = 0, unions = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    unordered_map<string, int> m1; unordered_map<string, int> m2;
    
    input_data(str1, m1); input_data(str2, m2);
    
    for(auto it = m1.begin(); it != m1.end(); it++) {
        inter += min(it -> second, m2[it -> first]);
        unions += max(it -> second, m2[it -> first]);
        m2[it -> first] = 0;
    }
    
    for(auto it = m2.begin(); it != m2.end(); it++) {
        if (it -> second != 0) {
            unions += it -> second;
        }
    }
    if (unions == 0) {return 65536;}
    return (inter/unions * 65536);
}
