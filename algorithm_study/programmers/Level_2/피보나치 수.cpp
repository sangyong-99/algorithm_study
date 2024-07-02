//
//  피보나치 수.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/2/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a[100010];
    a[0] = 0;
    a[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        a[i] = (a[i-1] + a[i-2]) % 1234567;
    }
    answer = a[n];
    return answer;
}
