//
//  5014.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/19/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> datas(1000010, -1);
vector<int> moves;
int F, S, G, U, D;
queue<pair<int, int>> bfs_queue;


void input() {
    cin >> F >> S >> G >> U >> D;
    moves.push_back(U);
    moves.push_back(D * -1);
    bfs_queue.push({S, 0});
    datas[S] = 0;
}

int main() {
    input();

    while (!bfs_queue.empty()) {
        auto bfs = bfs_queue.front();
        bfs_queue.pop();

        for (int i = 0; i < moves.size(); i++) {
            int dStairs = bfs.first + moves[i];
            if (dStairs < 1 || dStairs > F) { continue; }
            if (datas[dStairs] != -1) { continue; }
            int countss = bfs.second + 1;
            datas[dStairs] = countss;
            bfs_queue.push({dStairs, countss});
        }
    }
    if (datas[G] == -1) {
        cout << "use the stairs";
    } else {
        cout << datas[G];
    }
    return 0;
}
