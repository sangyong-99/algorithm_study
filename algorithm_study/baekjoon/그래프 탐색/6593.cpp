//
//  6593.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/24/24.
//

#include <bits/stdc++.h>

#define x(q) get<0>(q)
#define y(q) get<1>(q)
#define z(q) get<2>(q)

using namespace std;

struct BFS {
    char data;
    int counts = 0;
    int vis = false;
};

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 1, -1, 0, 0};

queue<tuple<int, int, int>> bfs_queue;
string s;
tuple<int, int, int> end_position;
vector<vector<vector<BFS>>> datas(35, vector<vector<BFS>>(35, vector<BFS>(35)));
int L, R, C;

void input() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            cin >> s;
            for (int z = 0; z < C; z++) {
                datas[i][j][z].data = s[z];
                if (s[z] == 'S') {
                    bfs_queue.push({i, j, z});
                    datas[i][j][z].vis = true;
                }
                if (s[z] == 'E') { end_position = make_tuple(i, j, z); }
            }
        }
    }
}

void clear() {
    datas = vector<vector<vector<BFS>>>(35, vector<vector<BFS>>(35, vector<BFS>(35)));
    while (!bfs_queue.empty()) { bfs_queue.pop(); }
}

void solution() {
    while (!bfs_queue.empty()) {
        auto qu = bfs_queue.front();
        bfs_queue.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x(qu) + dx[i];
            int ny = y(qu) + dy[i];
            int nz = z(qu) + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) { continue; }
            if (datas[nx][ny][nz].data == '#' || datas[nx][ny][nz].vis) { continue; }
            bfs_queue.push({nx, ny, nz});
            datas[nx][ny][nz].vis = true;
            datas[nx][ny][nz].counts = datas[x(qu)][y(qu)][z(qu)].counts + 1;

        }
    }
}

int main() {
    while (true) {
        clear();
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) {
            break;
        }
        input();
        solution();
        if (datas[x(end_position)][y(end_position)][z(end_position)].counts == 0) {
            cout << "Trapped!" << '\n';
        } else {
            cout << "Escaped in " << datas[x(end_position)][y(end_position)][z(end_position)].counts
                 << " minute(s)." << '\n';
        }
    }
    return 0;
}
