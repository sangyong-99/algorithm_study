//
//  1012.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/9/24.
//

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct BFS {
    int datas;
    bool visited = false;
};

int T, M, N, K, X, Y;
queue<pair<int, int>> bfs_queue;
queue<pair<int, int>> bfs_qu;
BFS bfs_datas[60][60];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    fill_n(&bfs_datas[0][0], 60 * 60, BFS());
    // bfs_datas[60][60] 초기화 재생성하는 방법
    cin >> M >> N >> K;
    while (K--) {
        cin >> X >> Y;
        bfs_datas[X][Y].datas = 1;
        bfs_queue.push({X, Y});
    }
}

int solution() {
    int count = 0;
    while (!bfs_queue.empty()) {
        auto qu = bfs_queue.front(); bfs_queue.pop();
        if (bfs_datas[qu.x][qu.y].visited) continue;
        bfs_datas[qu.x][qu.y].visited = true;
        bfs_qu.push(qu);
        while (!bfs_qu.empty()) {
            auto temp = bfs_qu.front(); bfs_qu.pop();
            for (int i = 0; i < 4; i++){
                int nx = temp.x + dx[i];
                int ny = temp.y + dy[i];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                if (bfs_datas[nx][ny].datas == 0 || bfs_datas[nx][ny].visited) continue;
                bfs_datas[nx][ny].visited = true;
                bfs_qu.push({nx, ny});
            }
        }
        count++;
    }
    return count;
}

int main() {
    cin >> T;
    while (T--) {
        input();
        cout << solution() << endl;
    }
}
