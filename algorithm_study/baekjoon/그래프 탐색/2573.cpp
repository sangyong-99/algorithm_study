//
//  2573.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/24/24.
//

#include <bits/stdc++.h>

#define MAX 310
using namespace std;

int maps[MAX][MAX];
int minuss[MAX][MAX];
bool visited[MAX][MAX];
int N, M;
queue<pair<int, int>> bfs_queue;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maps[i][j];
        }
    }
}

// 마이너스 할 값 구하기
void mi() {
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (maps[i][j] != 0) {
                int counts = 0;
                for (int z = 0; z < 4; z++) {
                    int nx = i + dx[z];
                    int ny = j + dy[z];
                    if (maps[nx][ny] == 0) {
                        counts++;
                    }
                }
                minuss[i][j] = counts;
            }
        }
    }
}

void minusExec() {
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            maps[i][j] -= minuss[i][j];
            if (maps[i][j] <= 0) maps[i][j] = 0;
            else {
                bfs_queue.push({i, j});
            }
        }
    }
}

int bfs() {
    int counts = 0;
    while (!bfs_queue.empty()) {
        auto qu = bfs_queue.front();
        bfs_queue.pop();

        if (visited[qu.first][qu.second]) { continue; }
        queue<pair<int, int>> bfs_qu;
        visited[qu.first][qu.second] = true;
        bfs_qu.push({qu.first, qu.second});
        counts++;
        while (!bfs_qu.empty()) {
            auto [x, y] = bfs_qu.front();
            bfs_qu.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (maps[nx][ny] == 0 || visited[nx][ny]) { continue; }
                visited[nx][ny] = true;
                bfs_qu.push({nx, ny});
            }
        }
    }
    return counts;
}

void clear() {
    memset(visited, false, sizeof(visited));
}

int main() {
    input();
    int time = 0;
    while (true) {
        time++;
        mi();
        minusExec();
        clear();
        // 모두가 0인 빙산이 없는 경우 빠져나와서 0 출력
        if (bfs_queue.empty()) { break; }
        int result = bfs();
        if (result != 1) {
            cout << time;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
