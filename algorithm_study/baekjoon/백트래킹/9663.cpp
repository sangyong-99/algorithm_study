//
//  9663.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/24/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, result;
int row[20];
int datas[20][20];


bool check(int level) {
    for(int i = 0; i < level; i++) {
        if (row[i] == row[level] || abs(row[level] - row[i]) == level - i) return false;
    }
    return true;
}

void nqueen(int x) {    // x는 행
    if (x == N) {result++; return;}
    
    for(int i = 0; i < N; i++) {    // i는 열
        row[x] = i;
        if (check(x)) nqueen(x+1);
    }
}

int main() {
    cin >> N;
    nqueen(0);
    cout << result;
}
