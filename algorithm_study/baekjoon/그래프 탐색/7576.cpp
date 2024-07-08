//
//  7576.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/8/24.
//

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct BFS {
    int visited = -1;
    int data;
    
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int M, N, temp, maxDay;
queue<pair<int, int>> bfs_data1;
BFS bfs_data[1010][1010];

void input() {
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            bfs_data[i][j].data = temp;
            if (temp == 1) {
                bfs_data1.push({i, j});
                bfs_data[i][j].visited = 0;
            }
        }
    }
}

void solution() {
    while (!bfs_data1.empty()) {
        pair<int, int> data1 = bfs_data1.front();
        bfs_data1.pop();
        temp = bfs_data[data1.x][data1.y].visited;
        for (int i = 0; i < 4; i++) {
            int nx = data1.x + dx[i];
            int ny = data1.y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && bfs_data[nx][ny].visited == -1 && bfs_data[nx][ny].data == 0) {
                bfs_data[nx][ny].visited = (temp + 1);
                bfs_data[nx][ny].data = 1;
                bfs_data1.push({nx, ny});
            }
        }
    }

}

int print_result () {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (bfs_data[i][j].data == 0) {return -1;}
            maxDay = max(maxDay, bfs_data[i][j].visited);
        }
    }
    return maxDay;
}

int main() {
    input();
    solution();
    cout << print_result();
}
