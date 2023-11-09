//
//  가장 가까운 같은 글자.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/10/23.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int datas[30];
    fill(datas, datas+30, -1);
    
    for(int i = 0; i < s.length(); i++) {
        if (datas[s[i] - 'a' + 1] == -1) {
            answer.push_back(-1);
            datas[s[i] - 'a' + 1] = i;
            continue;
        } else {
            int temp = i - (datas[s[i] - 'a' + 1]);
            answer.push_back(temp);
            datas[s[i] - 'a' + 1] = i;
            continue;
        }
    }
    return answer;
}
