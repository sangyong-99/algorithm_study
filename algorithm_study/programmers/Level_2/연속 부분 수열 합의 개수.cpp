//
//  연속 부분 수열 합의 개수.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/13/24.
//

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    for(int i = 0; i < elements.size(); i++) {  // index 값
        for(int j = 1; j < elements.size(); j++) {  // 더하는 개수 값
            int sum = 0;
            int temp = i;
            for(int z = 0; z < j; z++) { // 반복 돌리기
                sum += elements[(temp + z) % elements.size()];
            }
            s.insert(sum);
        }
    }
    int sum = 0;
    for(int i = 0; i < elements.size(); i++) {  // index 값
        sum += elements[i];
    }
    s.insert(sum);
    return s.size();
}
