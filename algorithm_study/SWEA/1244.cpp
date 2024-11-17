//
//  1244.cpp
//  algorithm_study
//
//  Created by 신상용 on 10/27/24.
//

#include<bits/stdc++.h>
using namespace std;

string str;
int attemptCount = 0, answer = 0;
bool visited[1000000][11];

void dfs(int count) {
    if (count == attemptCount) {
        answer = max(answer, stoi(str));
        return;
    }
    bool flag = false;
    for(int i = 0; i < str.length(); i++) {
        for(int j = i + 1; j < str.length(); j++) {
            if (str[i] <= str[j]) {
                flag = true;
                swap(str[i], str[j]);
                
                if (!visited[stoi(str)][count]) {
                    visited[stoi(str)][count] = true;
                    dfs(count+1);
                }
                
                swap(str[i], str[j]);
            }
        }
    }
    if (!flag) {
        swap(str[str.length() - 2], str[str.length() - 1]);
        if (!visited[stoi(str)][count]) {
            visited[stoi(str)][count] = true;
            dfs(count+1);
        }
        swap(str[str.length() - 2], str[str.length() - 1]);
    }
}

int main(int argc, char** argv) {
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case) {
        cin >> str; cin >> attemptCount;
        answer = 0;
        memset(visited,false,sizeof(visited));
        dfs(0);
        printf("#%d %d\n", test_case, answer);
    }
    return 0;
}
