//
//  [3차] 압축.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/14/25.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> mm;
    int ans = 27;
    for(int i = 65; i < 91; i++) {
        string s(1, i);
        mm[s] = (i - 64);
    }
    
    string standard = "";
    bool find = false;
    for(int i = 0; i < msg.length(); i++) {
        if (!find) {standard = "";}
        standard += msg[i];
        
        string temp = "";
        
        if ((i + 1) < msg.length()) {
            temp = standard + msg[i+1];
        }
        
        if (mm.find(temp) != mm.end()) {
            
            find = true;
            cout << "found";
        } else {
            answer.push_back(mm[standard]);
            if ((i + 1) < msg.length()) {
                mm[temp] = ans;
                ans++;
            }
            find = false;
            cout << "not found";
        }
        
    }
    
    return answer;
}
