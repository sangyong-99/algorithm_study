//
//  2206.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/24/24.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
int N, M;
string s;
int maps[MAX][MAX];
int distances[MAX][MAX][2];
bool visited[MAX][MAX][2];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            maps[i][j] = s[j] - '0';
        }
    }
}

int bfs() {
    queue<tuple<int, int, int>> bfs_queue;
    visited[0][0][0] = true;
    distances[0][0][0] = 1;
    bfs_queue.push({0, 0, 0});
    while (!bfs_queue.empty()) {
        auto [x, y, wall] = bfs_queue.front();
        bfs_queue.pop();

        if (x == N - 1 && y == M - 1) { return distances[x][y][wall]; }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) { continue; }
            // 벽일때
            if (maps[nx][ny] == 1) {
                if (wall == 0 && !visited[nx][ny][1]) {
                    visited[nx][ny][1] = true;
                    distances[nx][ny][1] = distances[x][y][wall] + 1;
                    bfs_queue.push({nx, ny, 1});
                }
            }
            // 벽이 아닐때
            else {
                if (!visited[nx][ny][wall]) {
                    visited[nx][ny][wall] = true;
                    distances[nx][ny][wall] = distances[x][y][wall] + 1;
                    bfs_queue.push({nx, ny, wall});
                }
            }
        }
    }
    return -1;
}

int main() {
    input();
    int result = bfs();
    if (result == -1)
        cout << "-1" << endl;
    else
        cout << result << endl;

    return 0;
}
