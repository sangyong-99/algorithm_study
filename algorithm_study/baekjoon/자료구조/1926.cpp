//
//  1926.cpp
//  algorithm_study
//
//  Created by 신상용 on 6/29/24.
//

#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

struct BFS {
    int map;
    bool vis;
};

int n, m, temp, maxss, per_count, counts;
BFS datas[502][502];
queue<pair<int, int>> init_queue;
queue<pair<int, int>> bfs_queue;
int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> datas[i][j].map;
            if (datas[i][j].map) {
                init_queue.push({i, j});
            }
        }
    }
    
    while (!init_queue.empty()) {
        pair<int, int> qu = init_queue.front();
        init_queue.pop();
        if (!datas[qu.X][qu.Y].vis) {
            per_count = 1;
            counts++;
            bfs_queue.push(qu);
            datas[qu.X][qu.Y].vis = true;
            while (!bfs_queue.empty()) {
                pair<int, int> q = bfs_queue.front(); bfs_queue.pop();
                
                for(int i = 0; i < 4; i++) {
                    int dx = q.X + nx[i];
                    int dy = q.Y + ny[i];
                    
                    if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
                    if (datas[dx][dy].vis || datas[dx][dy].map != 1) continue;
                    bfs_queue.push({dx, dy});
                    datas[dx][dy].vis = true;
                    per_count++;
                }
            }
            if (per_count > maxss) {
                maxss = per_count; 
            }
        }
    }
    cout << counts << "\n" << maxss;
}
