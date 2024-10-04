//
//  모음사전.cpp
//  algorithm_study
//
//  Created by 신상용 on 10/4/24.
//

#include <bits/stdc++.h>

using namespace std;

int answer = 0;
char datas[] = {'A', 'E', 'I', 'O', 'U'};
char results[5];
string str = "";

bool dfs (int n, int k, string word) {
    
    if (str.length() != 0) {
        if (str == word) {
            return true;
        }
    }
    if (k == 5) {
        return false;
    }
    
    for(int i = 0; i < n; i++) {
        str += datas[i];
        answer++;
        bool finds = dfs(n, k+1, word);
        if (finds) {return true;}
        str.erase(str.end() - 1);
        
    }
    
    return false;
}

int solution(string word) {
    dfs(5, 0, word);
    cout << answer;
    return answer;
}

int main() {
    solution("AAAAE");
}
