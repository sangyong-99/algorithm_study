//
//  13549.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/24/24.
//

#include <bits/stdc++.h>

#define MAX 200010
using namespace std;

bool visited[MAX];
int times[MAX];
int N, K;

int dx[2] = {-1, 1};

void input() {
    cin >> N >> K;
}

int bfs() {
    deque<int> bfs_queue;
    bfs_queue.push_back({N});
    visited[N] = true;

    while (!bfs_queue.empty()) {
        int qu = bfs_queue.front();
        bfs_queue.pop_front();

        if (qu == K) {
            cout << times[qu];
            return 0;
        }

        int multiX = qu * 2;
        if (multiX < MAX && !visited[multiX]) {
            bfs_queue.push_front({multiX});
            visited[multiX] = true;
            times[multiX] = times[qu];
        }
        for (int i = 0; i < 2; i++) {
            int nx = qu + dx[i];
            if (nx < 0 || nx >= 200010) { continue; }
            if (visited[nx]) { continue; }
            bfs_queue.push_back({nx});
            visited[nx] = true;
            times[nx] = times[qu] + 1;
        }
    }
}

int main() {
    input();
    bfs();
    return 0;
}
