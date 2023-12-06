//
//  달리기 경주(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 12/6/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string, int> um;
    
    for(int i = 0; i < players.size(); ++i) um[players[i]] = i;
    for(string s : callings) {
        int index = um[s];
        um[players[index - 1]]++;
        um[s]--;
        swap(players[index - 1], players[index]);
    }
    
    return players;
}
