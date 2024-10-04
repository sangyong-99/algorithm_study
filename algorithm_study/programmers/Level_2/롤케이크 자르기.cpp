//
//  롤케이크 자르기.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 10/5/24.
//

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> datas1;
unordered_map<int, int> datas2;

int solution(vector<int> topping) {
    int answer = 0;
    for(int i = 0; i < topping.size(); i++) {
        datas2[topping[i]]++;
    }
    
    for(int i = 0; i < topping.size(); i++) {
        datas1[topping[i]]++;
        datas2[topping[i]]--;
        if (datas2[topping[i]] == 0) {
            datas2.erase(datas2.find(topping[i]));
        }
        if (datas1.size() == datas2.size()) answer++;
    }
    
    return answer;
}
