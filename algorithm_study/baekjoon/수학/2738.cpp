//
//  2738.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/12/22.
//

#include <bits/stdc++.h>
using namespace std;

int N, M, a[101][101], b[101][101], c[101][101];
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
    
}
