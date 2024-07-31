//
//  7569.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/13/24.
//

#include <bits/stdc++.h>
using namespace std;

struct BFS {
    int data;
    bool visited = false;
    int count = 0;
};

void print_data();
int M, N, H;
BFS datas[110][110][110];
queue<tuple<int, int, int>> qu;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin >> M >> N >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int z = 0; z < M; z++) {
                cin >> datas[i][j][z].data;
                if (datas[i][j][z].data == 1){
                    qu.push({i, j, z});
                }
            }
        }
    }
}

void bfs_solution() {
    while (!qu.empty()) {
        auto q = qu.front(); qu.pop();
        datas[get<0>(q)][get<1>(q)][get<2>(q)].visited = true;
        for(int i = 0; i < 4; i++) {
            int nx = get<1>(q) + dx[i];
            int ny = get<2>(q) + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) { continue; }
            if (datas[get<0>(q)][nx][ny].data != 0 || datas[get<0>(q)][nx][ny].visited) { continue; }
            datas[get<0>(q)][nx][ny].visited = true;
            datas[get<0>(q)][nx][ny].count += datas[get<0>(q)][get<1>(q)][get<2>(q)].count;
            datas[get<0>(q)][nx][ny].data = 1;
            qu.push({get<0>(q), nx, ny});
        }
    }
}

int main() {
    input();
    bfs_solution();
    cout << endl;
    print_data();
    
}


void print_data() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int z = 0; z < M; z++) {
                cout << datas[i][j][z].data << " ";
            }
            cout << '\n';
        }
    }
}
