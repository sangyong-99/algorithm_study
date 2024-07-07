//
//  카펫.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/7/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1; i <= yellow ; i++) {
        if (yellow % i == 0) {
            int temp = yellow / i;
            if (((i * 2) + (temp * 2) + 4) == brown) {
                answer.push_back(i+2);
                answer.push_back(temp + 2);
                break;
            }
        }
    }
    sort(answer.begin(), answer.end(), greater<>());
    return answer;
}
