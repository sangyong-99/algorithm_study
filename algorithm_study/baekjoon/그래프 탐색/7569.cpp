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

int M, N, H;
BFS datas[110][110][110];
queue<tuple<int, int, int>> qu;


int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int printData() {
    int maxs = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int z = 0; z < M; z++) {
                maxs = max(maxs, datas[i][j][z].count);
            }
        }
    }
    
    return maxs;
}

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
        
        
        for(int i = 0; i < 6; i++) {
            int nx = get<1>(q) + dx[i];
            int ny = get<2>(q) + dy[i];
            int nz = get<0>(q) + dz[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) { continue; }
            if (datas[nz][nx][ny].data != 0 || datas[nz][nx][ny].visited) { continue; }
            datas[nz][nx][ny].visited = true;
            datas[nz][nx][ny].count = datas[get<0>(q)][get<1>(q)][get<2>(q)].count + 1;
            datas[nz][nx][ny].data = 1;
            qu.push({nz, nx, ny});
        }
    }
}

bool print_result() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int z = 0; z < M; z++) {
                if(datas[i][j][z].data == 0) {
                    return false;
                }
                
            }
//            cout << "\n";
        }
    }
    return true;
}

int main() {
    input();
    bfs_solution();
    cout << (print_result() ? printData() : -1);
    print_result();
}






