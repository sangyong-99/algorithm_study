//
//  달리기 경주(1).cpp
//  algorithm_study
//
//  Created by 신상용 on 12/6/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    for(int i = 0; i < callings.size(); i++) {
        auto it = find(players.begin(), players.end(), callings[i]);
        int index = it - players.begin();
        players.erase(it);
        players.insert(players.begin() + (index - 1), callings[i]);
    }
    
    answer.assign(players.begin(), players.end());
    
    return answer;
}
