//
//  5215.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/13/24.
//

#include<bits/stdc++.h>

using namespace std;

int result, N, L, temp1, temp2, score, calor;
vector<pair<int, int>> v;
bool used[25];

void input() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
}

void dfs(int index) {

    for (int i = index; i < N; i++) {
        if (calor + v[i].second <= L) {
            score += v[i].first;
            calor += v[i].second;
            result = max(result, score);
            dfs(i + 1);
            score -= v[i].first;
            calor -= v[i].second;
        }
    }
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        result = 0;
        score = 0;
        calor = 0;
        v.clear();
        input();
        dfs(0);
        cout << "#" << test_case << " " << result << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
