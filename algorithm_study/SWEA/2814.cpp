//
//  2814.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/14/24.
//

#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> datas;
int N, M, result, x, y;
bool visited[25];

void input_data() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        datas.push_back({x, y});
        datas.push_back({y, x});
    }
}

void dfs(int index, int count) {
    if (result < count) result = count;

    for (int i = 0; i < datas.size(); i++) {
        if (datas[i].first == index && !visited[datas[i].second]) {
            visited[datas[i].second] = true;
            dfs(datas[i].second, count + 1);
            visited[datas[i].second] = false;
        }
    }
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        datas.clear();
        memset(visited, false, sizeof(visited));
        result = 0;
        input_data();
        for (int i = 1; i <= N; i++) {
            visited[i] = true;
            dfs(i, 1);
            visited[i] = false;
        }
        cout << "#" << test_case << " " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
