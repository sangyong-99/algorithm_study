//
//  게임 맵 최단거리.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 9/23/24.
//

#include<bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct BFS {
    bool visited = false;
    int datas = 0;
    int counts = 0;
};

BFS bfs_datas[110][110];
queue<pair<int, int>> bfs_queue;

void input_data(vector<vector<int> > maps) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bfs_datas[i][j].datas = maps[i][j];
        }
    }
}

int solution(vector<vector<int> > maps)
{
    n = maps.size(); m = maps[0].size();
    input_data(maps);
    bfs_queue.push({0, 0});
    bfs_datas[0][0].visited = true; bfs_datas[0][0].counts = 1;
    while(!bfs_queue.empty()) {
        auto qu = bfs_queue.front(); bfs_queue.pop();
        int temp_counts = bfs_datas[qu.first][qu.second].counts;
        for(int i = 0; i < 4; i++) {
            int nx = qu.first + dx[i];
            int ny = qu.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {continue;}
            if (bfs_datas[nx][ny].visited || bfs_datas[nx][ny].datas == 0) {continue;}
            bfs_datas[nx][ny].visited = true; bfs_datas[nx][ny].counts = temp_counts + 1;
            bfs_queue.push({nx, ny});
        }
        
    }
    return bfs_datas[n - 1][m - 1].counts == 0 ? -1 : bfs_datas[n - 1][m - 1].counts;
}
