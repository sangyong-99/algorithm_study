//
//  덧칠하기.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/22/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    bool datas[n + 1];
    fill_n(datas, n + 1, true); //datas true로 변환
    for(int ii: section) {
        datas[ii] = false;
    }
    for(int i = 1; i <= n; i++) {
        if (!datas[i]) {
            if (i + m <= n){
                fill_n(datas + i, m, true);
            }
            i = i + (m - 1);
            answer++;
        }
    }
    return answer;
}
