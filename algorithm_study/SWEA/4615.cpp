//
//  4615.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/15/24.
//

#include<bits/stdc++.h>

using namespace std;

int N, M, x, y, color, temp1, temp2;
deque<tuple<int, int, int>> datas;
int result[15][15];
int dy[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dx[8] = {1, -1, 0, 1, -1, 0, 1, -1};

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> color;
        datas.push_back({x, y, color});
    }
}

void clear() {
    datas.clear();
    memset(result, 0, sizeof(result));
    temp1 = temp2 = 0;
}

void setup() {
    int temp = N / 2;
    result[temp - 1][temp - 1] = result[temp][temp] = 2;
    result[temp - 1][temp] = result[temp][temp - 1] = 1;
}

void setColor(int sx, int sy, int ex, int ey, int color, int dir) {
    while (sx != ex || sy != ey) {
        result[sx][sy] = color;
        sx += dx[dir];
        sy += dy[dir];
    }
}

void find(int x, int y, int color) {
    result[x][y] = color;
    for (int i = 0; i < 8; i++) {
        int nx = x;
        int ny = y;
        while (1) {
            nx += dx[i];
            ny += dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
            if (result[nx][ny] == 0) break;
            if (result[nx][ny] == color) {
                setColor(x, y, nx, ny, color, i);
                break;
            }
        }
    }
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        clear();
        input();
        setup();
        while (!datas.empty()) {
            auto dd = datas.front();
            datas.pop_front();
            find(get<1>(dd) - 1, get<0>(dd) - 1, get<2>(dd));
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (result[i][j] == 1) {
                    temp1++;
                } else if (result[i][j] == 2) {
                    temp2++;
                }
            }
        }
        cout << "#" << test_case << " " << temp1 << " " << temp2 << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
