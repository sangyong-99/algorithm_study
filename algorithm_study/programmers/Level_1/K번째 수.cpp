//
//  K번째 수.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/10/23.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(vector<int> ii : commands) {
        vector<int> temp;
        
        for(int i = ii[0] - 1; i < ii[1]; i++) {
            temp.push_back(array[i]);
            sort(temp.begin(), temp.end());
        }
        // cout << ii[0];
        
        answer.push_back(temp[ii[2] - 1]);
    }
    
    return answer;
}
