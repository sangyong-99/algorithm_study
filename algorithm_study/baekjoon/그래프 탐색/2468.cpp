//
//  2468.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/24/24.
//

#include <bits/stdc++.h>

using namespace std;

struct BFS {
    int data;
    bool visited = false;
};

int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, -1, 0, 1};

int N, temp, counts, result;
BFS datas[110][110];
queue<pair<int, int>> bfs_queue;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> datas[i][j].data;
        }
    }
}

void clear() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            datas[i][j].visited = false;
        }
    }
    while (!bfs_queue.empty()) bfs_queue.pop();
}

void setup(int stan) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (datas[i][j].data > stan) {
                bfs_queue.push({i, j});
            }
        }
    }
}

int solution(int stan) {
    int temp_result = 0;
    while (!bfs_queue.empty()) {
        auto qu = bfs_queue.front();
        bfs_queue.pop();
        if (datas[qu.first][qu.second].visited) { continue; }
        temp_result++;
        queue<pair<int, int>> bfs_qu;
        bfs_qu.push({qu.first, qu.second});
        datas[qu.first][qu.second].visited = true;
        while(!bfs_qu.empty()) {
            auto q = bfs_qu.front();
            bfs_qu.pop();
            for(int i = 0; i < 4; i++) {
                int nx = q.first + dx[i];
                int ny = q.second + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (datas[nx][ny].data <= stan || datas[nx][ny].visited) continue;
                bfs_qu.push({nx, ny});
                datas[nx][ny].visited = true;
            }
        }
    }
    return temp_result;
}

int main() {
    input();
    for (int i = 0; i <= 100; i++) {
        clear();
        setup(i);
        result = max(solution(i), result);
    }
    cout << result;
    return 0;
}
