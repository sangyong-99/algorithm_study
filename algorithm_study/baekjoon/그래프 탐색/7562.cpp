//
//  7562.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/15/24.
//

#include <bits/stdc++.h>

using namespace std;

struct BFS {
    int data;
    bool visited = false;
    int count = 0;
};

int T, l, x, y;
pair<int, int> start, endss;
int dx[8] = {1, 2, -1, -2, 1, 2, -1, -2};
int dy[8] = {2, 1, 2, 1, -2, -1, -2, -1};
queue <pair<int, int> > bfs_queue;
//BFS datas[310][310];
vector <vector<BFS> > datas(310, vector<BFS>(310));


void input_data() {
    cin >> l;
    cin >> x >> y;
    start = make_pair(x, y);
    bfs_queue.push(start);
    cin >> x >> y;
    endss = make_pair(x, y);
    datas[x][y].data = 1;

}

int solution() {
    if (start == endss) {
        return 0;
    }
    datas[start.first][start.second].visited = true;
    while (!bfs_queue.empty()) {
        pair<int, int> qu = bfs_queue.front();
        bfs_queue.pop();
        datas[qu.first][qu.second].visited = true;
        for (int i = 0; i < 8; i++) {
            int nx = qu.first + dx[i];
            int ny = qu.second + dy[i];
            if (nx < 0 || nx >= l || ny < 0 || ny >= l) { continue; }
            if (datas[nx][ny].visited) { continue; }
            auto new_point = make_pair(nx, ny);
            if (new_point == endss) {
                return datas[qu.first][qu.second].count += 1;
            } else {
                datas[new_point.first][new_point.second].count = datas[qu.first][qu.second].count + 1;
                datas[new_point.first][new_point.second].visited = true;
                bfs_queue.push(new_point);
            }
        }
    }
    return datas[endss.first][endss.second].count;
}

void clear() {
    while (!bfs_queue.empty()) { bfs_queue.pop(); }
    datas = vector < vector < BFS > > (310, vector<BFS>(310));
}

int main() {
    cin >> T;
    while (T--) {
        input_data();
        cout << solution() << '\n';
        clear();
    }
}
