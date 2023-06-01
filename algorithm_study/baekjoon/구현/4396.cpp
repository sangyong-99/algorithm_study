//
//  4396.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/06/01.
//

#include <bits/stdc++.h>
using namespace std;

int n;
char open_datas[13][13], bomb_datas[13][13], resultss[13][13];
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
bool lose = false;

void input_data(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> bomb_datas[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> open_datas[i][j];
        }
    }
    
}


int main(){
    input_data();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int countss = 0;        // 주위 폭탄 개수
            if (open_datas[i][j] == 'x') {
                
                    if (bomb_datas[i][j] == '*'){       // 폭탄 건들임
//                        cout << "*";
                        resultss[i][j] = '*';
                        lose = true;
                    } else {        // 폭탄 건들이지 않았을때
                        for(int z = 0; z < 8; z++) {
                            int nx = i + dx[z]; int ny = j + dy[z];     // 현재 탐색하는 인덱스
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n && (bomb_datas[nx][ny] == '*')) {
                                countss++;
                            }
                        }
//                        cout << countss;
                        resultss[i][j] = (char)countss;
                    }
                
            } else {
//                cout << '.';
                resultss[i][j] = '.';
            }
        }
//        cout << '\n';
    }
    if (lose) {
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (bomb_datas[i][j] == '*'){
                    resultss[i][j] = '*';
                }
            }
        }
    }
    
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (resultss[i][j] == '.'){
                    cout << '.';
                } else if (resultss[i][j] == '*'){
                    cout << '*';
                }
                else {
                    cout << (int)resultss[i][j];
                }
            }
            cout << '\n';
        }
    
}
