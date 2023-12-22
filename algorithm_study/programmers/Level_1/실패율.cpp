//
//  실패율.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/22/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, double> &a, const pair<int, double> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> vec;
    int datas[510] = {0, };
    sort(stages.begin(), stages.end());
    for(int ii: stages) {
        datas[ii]++;
    }
    int peopleNum = stages.size();
    
    for(int i = 1; i <= N; i++) {
        if (peopleNum == 0) {
            vec.push_back(make_pair(i, 0.0));
        } else {
            vec.push_back(make_pair(i, datas[i]/(double)peopleNum));
            peopleNum -= datas[i];
        }
    }
    sort(vec.begin(), vec.end(), compare);
    
    for(int i = 0; i < vec.size(); i++) {
        answer.push_back(vec[i].first);
    }
    return answer;
}
