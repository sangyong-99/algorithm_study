//
//  숫자의 표현.cpp
//  algorithm_study
//
//  Created by 신상용 on 6/17/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n/2; i++) {
        int temp = i;
        for(int j = i + 1; j <= n; j++) {
            temp += j;
            if (temp > n) {
                break;
            }
            else if (temp == n) {
                cout << i;
                answer++;
                break;
            }
        }
    }
    answer++;
    return answer;
}
