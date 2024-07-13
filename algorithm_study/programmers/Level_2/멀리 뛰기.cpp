//
//  멀리 뛰기.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/13/24.
//

#include <bits/stdc++.h>

using namespace std;

long long datas[2010];

long long solution(int n) {
    long long answer = 0;
    
    if (n < 3) {
        return n;
    }
    
    datas[1] = 1; datas[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        datas[i] = (datas[i - 1] + datas[i-2]) % 1234567;
    }
    
    return datas[n];
}
