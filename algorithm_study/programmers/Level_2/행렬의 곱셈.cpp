//
//  행렬의 곱셈.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/31/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr3;

vector<int> calculate(vector<int> arr1) {
    vector<int> calTemp;
    for(vector<int> v: arr3) {
        int temp = 0;
        for(int i = 0; i < v.size(); i++) {
            temp += arr1[i] * v[i];
        }
        calTemp.push_back(temp);
    }
    return calTemp;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < arr2[0].size(); i++) {
        vector<int> v;
        for(int j = 0; j < arr2.size(); j++) {
            v.push_back(arr2[j][i]);
        }
        arr3.push_back(v);
    }
    
    for(vector<int> v: arr1) {
        auto temp = calculate(v);
        answer.push_back(temp);
    }
    
    return answer;
}
