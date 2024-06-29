//
//  2178.cpp
//  algorithm_study
//
//  Created by 신상용 on 6/29/24.
//

#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

struct BFS {
    int map;
    int distance = INT_MAX;
    bool vis;
};

int N, M, results;
BFS datas[110][110];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, -1, 0, 1};
string input_s;

queue<pair<int, int>> bfs_queue;

void input_data() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> input_s;
        for(int j = 0; j < M; j++) {
            datas[i][j].map = input_s[j] - '0';
        }
    }
}

int main() {
    input_data();
    bfs_queue.push({0, 0});
    datas[0][0].distance = 1;
    datas[0][0].vis = true;
    while (!bfs_queue.empty()) {
        pair<int, int> qu = bfs_queue.front(); bfs_queue.pop();
        int temp_distance = datas[qu.X][qu.Y].distance;
        for(int i = 0; i < 4; i++) {
            int nx = qu.X + dx[i];
            int ny = qu.Y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (!datas[nx][ny].map || datas[nx][ny].vis) continue;
            
            bfs_queue.push({nx, ny});
            datas[nx][ny].vis = true;
            datas[nx][ny].distance = min(datas[nx][ny].distance, temp_distance + 1);
            
        }
        
    }
    cout << datas[N - 1][M - 1].distance << '\n';
}
