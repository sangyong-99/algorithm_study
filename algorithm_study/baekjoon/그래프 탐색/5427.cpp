//
//  5427.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/16/24.
//

#include <bits/stdc++.h>
using namespace std;

struct BFS {
    char data;
    bool visited = false;
    int count = 0;
};
int T, w, h;
char temp;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<BFS>> datas(1010, vector<BFS>(1010));
queue<pair<int, int>> fire;
queue<pair<int, int>> person;


int personExpand() {
    while (!person.empty()) {
        auto qu = person.front();
        if (qu.first == 0 || qu.second == 0 || qu.first == h - 1 || qu.second == w - 1) {return datas[qu.first][qu.second].count + 1;}
        person.pop();
        if (qu == pair<int, int>({-1, -1})) {if (!person.empty()) {person.push({-1, -1});} return 0;}
        int quCount = datas[qu.first][qu.second].count + 1;
        for(int i = 0; i < 4; i++) {
            int nx = qu.first + dx[i];
            int ny = qu.second + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {continue;}
            if (datas[nx][ny].data == '#' || datas[nx][ny].data == '*') {continue;}   // 벽이거나 불이면 pass
            if (datas[nx][ny].visited) {continue;}
            if (nx == 0 || ny == 0 || nx == h - 1 || ny == w - 1) {return quCount + 1;}
            datas[nx][ny].data = '@';
            datas[nx][ny].count = quCount;
            datas[nx][ny].visited = true;
            person.push({nx, ny});
            
            
        }
    }
    return 0;
}

void fireExpand() {
    while (!fire.empty()) {
        auto qu = fire.front();
        fire.pop();
        if (qu == pair<int, int>({-1, -1})) {if (!fire.empty()) {fire.push({-1, -1});} break;}
        for(int i = 0; i < 4; i++) {
            int nx = qu.first + dx[i];
            int ny = qu.second + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {continue;}
            if (datas[nx][ny].data == '#' || datas[nx][ny].data == '*') {continue;}   // 벽이거나 불이면 pass
            datas[nx][ny].data = '*';
            fire.push({nx, ny});
        }
        
    }
}
void print_Data() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << datas[i][j].data;
        }
        cout << endl;
    }
    cout << endl;
}

int solution() {
    while (true) {
        fireExpand();
        if (int i = personExpand()) {return i;}
        if (person.empty()) {return 0;}
//        print_Data();
    }
}

void clear() {
    datas = vector<vector<BFS>>(1010, vector<BFS>(1010));
    while (!fire.empty()) {fire.pop();}
    while (!person.empty()) {person.pop();}
}

void input_data() {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> temp;
            datas[i][j].data = temp;
            if (temp == '*') {
                fire.push({i, j});
            } else if (temp == '@') {
                person.push({i, j});
                datas[i][j].visited = true;
            }
        }
    }
    fire.push({-1, -1});
    person.push({-1, -1});
}

int main() {
    cin >> T;
    while (T--) {
        clear();
        input_data();
        int results = solution();
        if (results == 0) {cout << "IMPOSSIBLE" << '\n'; continue;}
        cout << results << '\n';
    }
}
