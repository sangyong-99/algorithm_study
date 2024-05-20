//
//  최솟값 만들기.cpp
//  algorithm_study
//
//  Created by 신상용 on 5/20/24.
//

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int i = 0; i < A.size(); i++) {
        answer += (A[i] * B[B.size() - i - 1]);
    }
    
    return answer;
}
