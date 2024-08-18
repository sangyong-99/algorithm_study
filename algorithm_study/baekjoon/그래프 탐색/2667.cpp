//
//  2667.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/17/24.
//

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

struct BFS {
    int data = 0;
    bool visited = false;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<BFS>> datas(30, vector<BFS>(30));
queue<pair<int, int>> bfs_queue;
queue<pair<int, int>> in_queue;
vector<int> results;
int N, counts;

void solution() {
    while (!bfs_queue.empty()) {
        auto qu = bfs_queue.front(); bfs_queue.pop();
        if (datas[qu.X][qu.Y].visited) {continue;}
        datas[qu.X][qu.Y].visited = true; counts++;
        in_queue.push({qu.X, qu.Y});
        int temp_count = 1;
        while (!in_queue.empty()) {
            auto qu = in_queue.front(); in_queue.pop();
            for(int i = 0; i < 4; i++) {
                int nx = qu.X + dx[i];
                int ny = qu.Y + dy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) {continue;}
                if (datas[nx][ny].data == 0 || datas[nx][ny].visited) {continue;}
                in_queue.push({nx, ny}); datas[nx][ny].visited = true;
                temp_count++;
            }
            
        }
        results.push_back(temp_count);
        
    }
}

void input_data() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < N; j++) {
            datas[i][j].data = s[j] - '0';
            if (datas[i][j].data == 1) {
                bfs_queue.push({i, j});
            }
        }
    }
}

int main() {
    input_data();
    solution();
    sort(results.begin(), results.end());
    cout << counts << '\n';
    for(int i: results) {
        cout << i << '\n';
    }
}
