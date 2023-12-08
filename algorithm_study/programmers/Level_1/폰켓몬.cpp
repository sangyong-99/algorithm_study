//
//  폰켓몬.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 12/8/23.
//

#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int counts = 0;
    bool datas[200010] = {false, };
    
    for(int i : nums) {
        if (!datas[i]) {
            counts++;
            datas[i] = true;
        }
    }
    int temp = nums.size() / 2;
    
    if (temp < counts) {
        return temp;
    } else {
        return counts;
    }
}
