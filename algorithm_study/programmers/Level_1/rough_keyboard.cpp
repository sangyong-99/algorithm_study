//
//  rough_keyboard.cpp
//  algorithm_study
//
//  Created by 신상용 on 3/17/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(const auto& s : targets){
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            int min = 101;
            for(int j = 0; j < keymap.size(); ++j){
                int pos = keymap[j].find(s[i]);
                if(pos != string::npos){
                    min = min < pos + 1 ? min : pos + 1;
                }
            }
            if(min == 101) {
                cnt = -1;
                break;
            }
            cnt += min;
        }
        answer.emplace_back(cnt);
    }
    return answer;
}
