//
//  최댓값과 최솟값.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 6/4/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int temp;
    istringstream in;
    in.str(s);
    in >> temp;
    int min = temp, max = temp;
    while (in >> temp) {
        if (temp < min) min = temp;
        if (temp > max) max = temp;
    }
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}
