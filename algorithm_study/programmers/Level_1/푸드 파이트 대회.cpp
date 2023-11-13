//
//  푸드 파이트 대회.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/13/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int datas[15];

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for(int i = 1; i < food.size(); i++) {
        for(int j = 0; j < food[i] / 2; j++) {
            temp += to_string(i);
        }
    }
  
    answer += temp;
    answer += '0';
    reverse(temp.begin(), temp.end());
    
    answer += temp;
    
    return answer;
}
