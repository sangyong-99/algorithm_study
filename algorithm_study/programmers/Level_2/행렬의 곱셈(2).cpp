//
//  행렬의 곱셈(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 9/1/24.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < arr1.size(); i++) {
        vector<int> v;
        for(int j = 0; j < arr2[0].size(); j++) {
            int sum = 0;
            for (int z = 0; z < arr2.size(); z++) {
                sum += arr1[i][z] * arr2[z][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
        
    }
    
    return answer;
}
