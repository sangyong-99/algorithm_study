//
//  카드 뭉치.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/30/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    unsigned int repeatCount = goal.size();
    for(int i = 0; i < repeatCount; i++) {
        if (goal.front() == cards1.front()) {
            cards1.erase(cards1.begin());
            goal.erase(goal.begin());
        }
        else if (goal.front() == cards2.front()) {
            cards2.erase(cards2.begin());
            goal.erase(goal.begin());
        }
        else return "No";
    }
    return "Yes";
}
