//
//  모의고사.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 12/9/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one[] = {1, 2, 3, 4, 5};
    int two[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int onesize = 5;
    int twosize = 8;
    int threesize = 10;
    int score[4] = {0, };
    
    int index;
    
    for(int i = 0; i < answers.size(); i++) {
        index = i % onesize;
        if (answers[i] == one[index]) {
            score[1]++;
        }
        
        index = i % twosize;
        if (answers[i] == two[index]) {
            score[2]++;
        }
        
        index = i % threesize;
        if (answers[i] == three[index]) {
            score[3]++;
        }
        
    }
    
    int maxs = 0;
    for(int i = 1; i <= 3; i++) {
        if (score[i] > maxs) {
            answer.clear();
            maxs = score[i];
            answer.push_back(i);
        } else if (score[i] == maxs) {
            maxs = score[i];
            answer.push_back(i);
        }
    }
    
    
    return answer;
}
