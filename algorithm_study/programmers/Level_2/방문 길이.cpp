//
//  방문 길이.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 10/6/24.
//

#include <iostream>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool datas[11][11][4];

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    
    for(char c: dirs) {
        int dir = 0;
        switch (c) {
            case 'L':
                dir = 0;
                break;
            case 'U':
                dir = 1;
                break;
            case 'R':
                dir = 2;
                break;
            default:
                dir = 3;
                break;
        }
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (nx < 0 || nx > 10 || ny < 0 || ny > 10) {continue;}
        int countdir = (dir + 2) % 4;
        if(!datas[x][y][dir] && !datas[nx][ny][countdir]){
            datas[x][y][dir] = true;
            datas[nx][ny][countdir] = true;
            answer++;
        }
        
        x = nx;
        y = ny;
    }
    
    return answer;
}

int main() {
    solution("ULURRDLLU");
}
