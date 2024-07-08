//
//  4179.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/8/24.
//

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct BFS {
    int firevisited = -1;
    int personvisisted = -1;
    char datas;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

BFS bfs_data[1010][1010];
queue<pair<int, int>> person_queue;
queue<pair<int, int>> fire_queue;
int R, C, results = INT_MAX;
string s;

void input() {
    cin >> R >> C;
    cin.ignore();
    for(int i = 0; i < R; i++) {
        getline(cin, s);
        for(int j = 0; j < C; j++) {
            bfs_data[i][j].datas = s[j];
            if (s[j] == 'J' || s[j] == 'F') {
                
                
                if (s[j] == 'J') {
                    person_queue.push({i, j});
                    bfs_data[i][j].personvisisted = 0;
                } else{
                    bfs_data[i][j].firevisited = 0;
                    fire_queue.push({i, j});
                }
            }
        }
    }
    person_queue.push({-1, -1});
    fire_queue.push({-1, -1});
}

void solution() {
    while (!person_queue.empty() || !fire_queue.empty()) {
        while (!fire_queue.empty()) {
            auto data = fire_queue.front();
            if (data.x == -1 && data.y == -1) {fire_queue.pop(); break;}
            int temp = bfs_data[data.x][data.y].firevisited;
            fire_queue.pop();
            for(int i = 0; i < 4; i++) {
                int nx = data.x + dx[i];
                int ny = data.y + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (bfs_data[nx][ny].firevisited != -1 || bfs_data[nx][ny].datas == '#') continue;
                fire_queue.push({nx, ny});
                bfs_data[nx][ny].firevisited = (temp + 1);
                bfs_data[nx][ny].datas = 'F';
            }
            
        }
        if (!fire_queue.empty()) {fire_queue.push({-1, -1});}
        
        while (!person_queue.empty()) {
            auto data = person_queue.front();
            if (data.x == -1 && data.y == -1) {person_queue.pop(); break;}
            int temp = bfs_data[data.x][data.y].personvisisted;
            person_queue.pop();
            for(int i = 0; i < 4; i++) {
                int nx = data.x + dx[i];
                int ny = data.y + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (bfs_data[nx][ny].personvisisted != -1 || bfs_data[nx][ny].datas == '#' || bfs_data[nx][ny].datas == 'F') continue;
                person_queue.push({nx, ny});
                bfs_data[nx][ny].personvisisted = (temp + 1);
                bfs_data[nx][ny].datas = 'J';
            }
            
            
        }
        if (!person_queue.empty()) {person_queue.push({-1, -1});}
    }
}

void print_result() {
    for(int i = 0; i < R; i++) {
        if (bfs_data[i][0].personvisisted != -1) results = min(results, bfs_data[i][0].personvisisted);
        if (bfs_data[i][C-1].personvisisted != -1) results = min(results, bfs_data[i][C-1].personvisisted);
    }
    for(int i = 0; i < C; i++) {
        if (bfs_data[0][i].personvisisted != -1) results = min(results, bfs_data[0][i].personvisisted);
        if (bfs_data[R-1][i].personvisisted != -1) results = min(results, bfs_data[R-1][i].personvisisted);
    }
    if (results == INT_MAX) {
        cout << "IMPOSSIBLE";
    }else { cout << results + 1;}
}

int main() {
    input();
    solution();
    print_result();
    
}
