//
//  땅따먹기.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 10/5/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> results(100010, vector<int>(4));

int maxss(int row, int col) {
    int maxValue = 0;
    for(int i = 0; i < 4; i++) {
        if (col != i && results[row][i] > maxValue) maxValue = results[row][i];
    }
    return maxValue;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int rows = land.size();
    for(int i = 0; i < 4; i++) {
        results[0][i] = land[0][i];
    }
    
    for(int row = 1; row < rows; row++) {
        for(int col = 0; col < 4; col++) {
            results[row][col] = maxss(row - 1, col) + land[row][col];
        }
    }
    
    return maxss(rows - 1, -1);
}
