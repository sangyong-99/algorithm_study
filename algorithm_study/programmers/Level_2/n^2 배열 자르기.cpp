//
//  n^2 배열 자르기.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/31/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long int i = left; i <= right; ++i)
    {
        long long y = i % n + 1;
        long long x = i / n + 1;
        long long int value = x >= y ? x : y;

        answer.push_back(value);
    }
    return answer;
}
