//
//  2583.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/17/24.
//

#include <bits/stdc++.h>
using namespace std;

struct BFS {
    int data = 0;
    bool visited = false;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int M, N, K, counts;
int sx, sy, ex, ey;
vector<vector<BFS>> datas(110, vector<BFS>(110));
queue<pair<int, int>> bfs_queue;
vector<int> results;

void input_data() {
    cin >> M >> N >> K;
    while (K--) {
        cin >> sx >> sy >> ex >> ey;
        for (int i = sy; i < ey; i++) {
            for (int j = sx; j < ex; j++) {
                datas[i][j].data = 1;
            }
        }
    }
}


void solution() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if (datas[i][j].data == 1 || datas[i][j].visited) {continue;}
            bfs_queue.push({i, j});
            datas[i][j].visited = true;
            counts++;
            int temp_count = 1;
            while (!bfs_queue.empty()) {
                
                auto qu = bfs_queue.front();
                bfs_queue.pop();
                for(int z = 0; z < 4; z++) {
                    int nx = qu.first + dx[z];
                    int ny = qu.second + dy[z];
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) {continue;}
                    if (datas[nx][ny].data == 1 || datas[nx][ny].visited) {continue;}
                    bfs_queue.push({nx, ny});
                    datas[nx][ny].visited = true;
                    temp_count++;
                }
                
            }
            results.push_back(temp_count);
        }
    }
}

int main() {
    input_data();
    solution();
    cout << counts << '\n';
    sort(results.begin(), results.end());
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << ' ';
    }
}
