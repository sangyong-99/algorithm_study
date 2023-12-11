//
//  소수 찾기.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/11/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    bool decimal[1000010];
    fill(decimal, decimal + 1000008, true);
    
    for(int i = 2; i < 500001; i++){
        if (decimal[i]) {
            for(int j = i*2; j < 1000005; j += i) {
                decimal[j] = false;
                
            }
        }
    }
    
    
    for(int i = 2; i <= n; i++) {
        if (decimal[i]) {
            answer++;
        }
    }
    
    return answer;
}
