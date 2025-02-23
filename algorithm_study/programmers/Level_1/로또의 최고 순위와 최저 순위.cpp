//
//  로또의 최고 순위와 최저 순위.cpp
//  algorithm_study
//
//  Created by 신상용 on 2/23/25.
//

#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int correctNum = 0;
    int zeroNum = 0;
    
    // 현재 일치하는 번호의 숫자와
    for (int i = 0; i < 6; i++) {
        if (lottos[i] == 0) {
            zeroNum++;
            continue;
        }
        
        if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) {
            // 찾았을 때
            correctNum++;
        }
    }
    
    int winner = 7-(correctNum + zeroNum);
    int loser = 7-(correctNum);
    
    if (winner == 7) {winner = 6;}
    if (loser == 7) {loser = 6;}
    
    answer.push_back(winner);
    answer.push_back(loser);
    cout << winner << " " << loser;
    
    return answer;
}
