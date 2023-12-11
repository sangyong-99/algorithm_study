//
//  기사단원의 무기.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/11/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int measureData[100010];
    measureData[1] = 1;
    
    for(int i = 2; i <= number; i++) {
        int counts = 0;
        for(int j = 1; j < sqrt(i); j++) {
            if (i % j == 0) {
                counts += 2;
            }
        }
        if ((sqrt(i) - ((int)sqrt(i))) == 0) {
            counts++;
        }
        measureData[i] = counts;
    }
    
    for(int i = 1; i <= number; i++)
        answer += (measureData[i] <= limit) ? measureData[i] : power;
    
    return answer;
}
