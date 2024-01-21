//
//  [1차]다트 게임.cpp
//  algorithm_study
//
//  Created by 신상용 on 1/21/24.
//

#include <string>
#include <bits/stdc++.h>

using namespace std;

int datass[3] = {0,};
int indexs = 0;

void SDT_Number(int prev, char SDT) {

    switch(SDT) {
        case 'S':
            datass[indexs] = pow(prev, 1);
            
            return;
        case 'D':
            datass[indexs] = pow(prev, 2);
            
            return;
        case 'T':
            datass[indexs] = pow(prev, 3);
            
            return;
    }
}

void options(char ch) {
    switch(ch) {
        case '*':
           if(indexs == 1) {
               datass[0] = datass[0] * 2;
           } else {
               datass [indexs-1] = datass [indexs-1] * 2;
               datass [indexs-2] = datass [indexs-2] * 2;
           }
            break;
        case '#':
            datass[indexs - 1] = datass[indexs - 1] * -1;
            break;
    }
}

int solution(string dartResult) {
    int answer = 0;
    
    for(int i = 0; i < dartResult.length(); i++) {
        if (isdigit(dartResult[i])) {
            if (isdigit(dartResult[i + 1])) {
                SDT_Number(10, dartResult[i + 2]);
                i++;
            } else {
                SDT_Number((dartResult[i]) - '0', dartResult[i+1]);
            }
            i++;
            indexs++;
            continue;
        } else {
            options(dartResult[i]);
        }
    }
    for(int ii: datass) {
        answer += ii;
    }
    return answer;
}
