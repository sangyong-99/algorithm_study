//
//  1941.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/25/24.
//

#include <bits/stdc++.h>
using namespace std;

struct BFS {
    int datas;
    bool visited;
};
int result;
string inputData[5];
int selec[30];
vector<vector<BFS>> bfs_data(7, vector<BFS>(7));
//BFS bfs_data[7][7];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void input_data() {
    for(int i = 0; i < 5; i++) {
        cin >> inputData[i];
    }
}

int somCount() {
    int som = 0;
    for(int i = 0; i < 25; i++) {
        int row = i / 5; int column = i % 5;
        if (selec[i] == 1) {
            bfs_data[row][column].datas = 1;
            if (inputData[row][column] == 'S') {
                som++;
            }
        }
    }
    return som;
}

bool bfs(pair<int, int> stan) {
    queue<pair<int, int>> bfs_queue;
    bfs_queue.push(stan);
    int count = 1;
    bfs_data[stan.first][stan.second].visited = true;
    while(!bfs_queue.empty()) {
        auto qu = bfs_queue.front();
        bfs_queue.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = qu.first + dx[i];
            int ny = qu.second + dy[i];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && bfs_data[nx][ny].datas == 1 && !bfs_data[nx][ny].visited) {
                count++;
                bfs_queue.push({nx, ny});
                bfs_data[nx][ny].visited = true;
            }
        }
    }
    return count == 7;
}

bool bfsStart() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (bfs_data[i][j].datas == 1) {
                return bfs({i, j});
            }
        }
    }
    return false;
}

void bfsInit() {
    bfs_data = vector<vector<BFS>> (7, vector<BFS>(7));
}

void combination(int idx, int cnt) {
    if (cnt == 7) {
        if (somCount() >= 4) {
            if (bfsStart()) {
                result++;
            }
        }
        bfsInit();
        return;
    }
    
    for(int i = idx; i < 25; i++) {
        selec[i] = 1;
        combination(i+1, cnt + 1);
        selec[i] = 0;
    }
}

int main() {
    input_data();
    combination(0, 0);
    cout << result;
}
