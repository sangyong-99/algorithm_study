//
//  2630.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/21/24.
//

#include <bits/stdc++.h>
using namespace std;

int N;
int datas[150][150];
map<int, int> results;

void input_data() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> datas[i][j];
        }
    }
}

void recur(int x, int y, int size) {
    int standard = datas[x][y];
    bool equals = true;
    for(int i = x; i < x + size; i++) {
        for(int j = y; j < y + size; j++) {
            if (datas[i][j] != standard) {
                equals = false; break;
            }
        }
    }
    
    if (equals) {results[standard]++; return;}
    
    recur(x, y, size / 2);
    recur(x, y + size/2, size / 2);
    recur(x + size/2, y, size / 2);
    recur(x + size/2, y + size / 2, size / 2);
    
}

int main() {
    input_data();
    recur(0, 0, N);
    cout << results[0] << '\n' << results[1];
}
