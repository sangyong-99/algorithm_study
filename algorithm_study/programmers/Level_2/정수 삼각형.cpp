//
//  정수 삼각형.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 10/6/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> datas(510, vector<int>(510));

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    datas[0][0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j <= triangle[i].size(); j++) {
            int left = 0, right = 0;
            if (j - 1 >= 0) {
                left = datas[i - 1][j - 1];
            }
            if (j <= i - 1) {
                right = datas[i - 1][j];
            }
            datas[i][j] = max(left, right) + triangle[i][j];
        }
    }
    
    for(int i = 0; i < triangle.size(); i++) {
        answer = max(answer, datas[triangle.size() - 1][i]);
    }
    return answer;
}
