//
//  14502.cpp
//  Test
//
//  Created by 신상용 on 2022/11/22.
//

#include <bits/stdc++.h>
using namespace std;

int N, M, arrays[10][10], visited[10][10], nx, ny, nx2, ny2;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int,int>> q;

void input_data(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arrays[i][j];
        }
    }
}

void solution1(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arrays[i][j] == 2){      //2이면 q에 삽입
                q.push({i, j});
            }
            if(arrays[i][j] != 0) visited[i][j] = 1; //0이 아니면 visited 에 1
        }
    }
    while(!q.empty()){
        nx = q.front().first;
        ny = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx2 = nx + dx[i];    ny2 = ny + dy[i];
            if(nx2 < 0 || ny2 < 0 || nx2 > N-1 || ny2 > M-1){
                continue;
            }
            if(arrays[nx2][ny2] == 0 && visited[nx2][ny2] == 0){
                arrays[nx2][ny2] = 2;
                q.push({nx2, ny2});
            }
        }
    }
    
}

int main(){
    cin >> N >> M;
    input_data();
    solution1();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arrays[i][j] << ' ';
        }
        cout << '\n';
    }
}

//4 6
//0 0 0 1 0 0
//1 0 0 1 0 2
//1 1 1 1 0 2
//0 0 0 1 0 2
