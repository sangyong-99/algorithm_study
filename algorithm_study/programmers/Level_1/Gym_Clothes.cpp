//
//  Gym_Clothes.cpp
//  algorithm_study
//
//  Created by 신상용 on 3/17/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> datass(n + 3, 1);
    
    for(int i: reserve) {
        datass[i]++;
    }
    
    for(int i: lost) {
        datass[i]--;
    }
    
    for(int i = 1; i <= n; i++) {
        if (datass[i] == 2) {
            if (datass[i-1] == 0) {
                datass[i]--;
                datass[i-1]++;
            } else if (datass[i+1] == 0 && (i+1) <= n) {
                datass[i]--;
                datass[i+1]++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if (datass[i] >= 1) {
            answer++;
        }
    }
    
    
    // 출력 코드
    for(int i : datass) {
        cout << i;
    }
    
    return answer;
}
