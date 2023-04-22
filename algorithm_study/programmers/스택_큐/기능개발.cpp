//
//  기능개발.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/22.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> answers;
    int buffers = 0;
    int counts = 0;
    int sizess = progresses.size();
    
    for(int i = 0; i < sizess; i++){
        answers.push_back(ceil((double)(100-progresses[i]) / speeds[i]));
    }
    
    for(int i = 1; i < sizess; i++){
        if (answers[i] < answers[i-1]){
            answers[i] = answers[i-1];
        }
    }
    // for(int i: answers){
    //     cout << i;
    // }
    buffers = answers[0];
    int dkdk;
    counts = 1;
    for(int i = 1; i < sizess; i++){
        if(buffers != answers[i]) {
            answer.push_back(counts);
            counts = 1;
            dkdk = i;
            buffers = answers[i];
            cout << counts;
        }
        else counts++;
    }
    if (dkdk < sizess) {
        answer.push_back(counts);
    }
    return answer;
}
