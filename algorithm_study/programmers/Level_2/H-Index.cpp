//
//  H-Index.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/2/24.
//

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h = 0;
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int i = 0; i < citations.size(); i++) {
        int cite = citations[i];
        if (h >= cite) {break;}
        h++;
    }
    
    return h;
}
