//
//  두 개 뽑아서 더하기.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/13/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> S;
    for(int i = 0; i < numbers.size() - 1; i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            S.insert(numbers[i] + numbers[j]);
        }
    }
    
    answer.assign(S.begin(), S.end());
    
    
    return answer;
}
