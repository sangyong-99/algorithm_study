//
//  10026.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/9/24.
//

#include <bits/stdc++.h>
using namespace std;

struct BFS {
    char datas;
    bool visited = false;
};

BFS bfs_datas[110][110];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N; string s;
queue<pair<int, int>> queue_data;

void input() {
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        for(int j = 0; j < N; j++) {
            bfs_datas[i][j].datas = s[j];
        }
    }
}

void clear() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            bfs_datas[i][j].visited = false;
        }
    }
}

int solution(int option) {
    clear();
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (bfs_datas[i][j].visited) continue;
            vector<char> color;
            color.push_back(bfs_datas[i][j].datas);
            if (option && (bfs_datas[i][j].datas == 'R' || bfs_datas[i][j].datas == 'G')) {
                color.push_back('R');
                color.push_back('G');
            }
            bfs_datas[i][j].visited = true;
            queue_data.push({i, j});
            while (!queue_data.empty()) {
                auto temp = queue_data.front(); queue_data.pop();
                for(int z = 0; z < 4; z++) {
                    int nx = temp.first + dx[z];
                    int ny = temp.second + dy[z];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (bfs_datas[nx][ny].visited || find(color.begin(), color.end(), bfs_datas[nx][ny].datas) == color.end()) continue;
                    queue_data.push({nx, ny});
                    bfs_datas[nx][ny].visited = true;
                }
            }
            count++;
        }
    }
    return count;
}

int main() {
    input();
    cout << solution(0) << " ";
    cout << solution(1);
}
