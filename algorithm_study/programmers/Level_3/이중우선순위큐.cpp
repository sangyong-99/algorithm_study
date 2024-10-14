//
//  이중우선순위큐.cpp
//  algorithm_study
//
//  Created by 신상용 on 10/15/24.
//

#include <bits/stdc++.h>

using namespace std;

multiset<int, less<int>> ms;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    string a; int b;
    for(string s: operations) {
        istringstream str(s);
        str >> a >> b;
        
        if (a == "I") ms.insert(b);
        else {
            if (b == 1 && !ms.empty()) ms.erase(--ms.end());
            else if (b == -1 && !ms.empty()) ms.erase(ms.begin());
        }
    }
    
    if (ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
    
    return answer;
}
