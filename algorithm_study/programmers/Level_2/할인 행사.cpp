//
//  할인 행사.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/31/24.
//

#include <bits/stdc++.h>
using namespace std;

bool check(map<string, int> standard, map<string, int> discountMap) {
    for(auto it = standard.begin(); it != standard.end(); it++) {
        string stanWant = it -> first;
        int stanNumber = it -> second;
        if (discountMap[stanWant] < stanNumber) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> standard;
    for(int i = 0; i < want.size(); i++) {
        standard[want[i]] = number[i];
    }
    // 먼저 10개 삽입
    map<string, int> discountMap;
    
    for(int i = 0; i <= 8; i++) {
        discountMap[discount[i]]++;
    }
    for(int i = 10; i<= discount.size(); i++) {
        discountMap[discount[i - 1]]++;
        if (check(standard, discountMap)) answer++;
        int firstIndex = i - 10;
        discountMap[discount[firstIndex]]--;
    }
    return answer;
}
