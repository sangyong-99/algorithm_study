//
//  소수 만들기.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/10/23.
//

#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    bool decimal[3000];
    
    fill(decimal, decimal+3000, true);
    
    for(int i = 2; i <= 1500; i++) {
        if (decimal[i]) {
            cout << i << " ";
            for(int j = i * 2; j <= 3000; j += i) {
                decimal[j] = false;
            }
        }
    }
    
    for(int i = 0; i < nums.size() - 2; i++) {
        for(int j = i + 1; j < nums.size() - 1; j++) {
            for(int z = j + 1; z < nums.size(); z++) {
                if (decimal[nums[i] + nums[j] + nums[z]]) {
                    answer++;
                }
            }
        }
    }
    
    
    

    return answer;
}
