//
//  예상 대진표.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/13/24.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while(a != b) {
        a = ceil((double)a / 2);
        b = ceil((double)b / 2);
        answer++;
    }

    return answer;
}
