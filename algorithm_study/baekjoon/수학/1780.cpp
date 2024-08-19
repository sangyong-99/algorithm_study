//
//  1780.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/19/24.
//

#include <bits/stdc++.h>
using namespace std;

int N;
int datas[2200][2200];
map<int, int> results;

void cut(int x, int y, int size) {
    int standard = datas[x][y];
    for(int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (standard != datas[i][j]) {goto B;}
        }
    }
    results[standard]++;
    return;
    B:
    cut(x, y, size/3);
    cut(x + size/3, y, size/3);
    cut(x + size/3*2, y, size/3);
    
    cut(x, y+size/3, size/3);
    cut(x + size/3, y+size/3, size/3);
    cut(x + size/3*2, y+size/3, size/3);
    
    cut(x, y + size/3*2, size/3);
    cut(x + size/3, y + size/3*2, size/3);
    cut(x + size/3*2, y + size/3*2, size/3);
}

void input_data() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> datas[i][j];
        }
    }
}

int main() {
    input_data();
    cut(0, 0, N);
    cout << results[-1] << '\n' << results[0] << '\n' << results[1];
}
