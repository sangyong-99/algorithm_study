//
//  1992.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/22/24.
//

#include <bits/stdc++.h>
using namespace std;

int N;
string s;
int datas[70][70];

void input_data() {
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        getline(cin, s);
        for(int j = 0; j < N; j++) {
            datas[i][j] = s[j] - '0';
        }
        
    }
}

void recur(int x, int y, int size) {
    int standard = datas[x][y];
    bool equals = true;
    for(int i = x; i < x + size; i++) {
        for(int j = y; j < y + size; j++) {
            if (datas[i][j] != standard) {equals = false; break;}
        }
    }
    // 다 같을 경우
    if (equals) {cout << standard; return;}
    // 다를 경우
    cout << "(";
    recur(x, y, size/2);
    recur(x, y + size/2, size/2);
    recur(x + size/2, y, size/2);
    recur(x + size/2, y + size/2, size/2);
    cout << ")";
}

int main() {
    input_data();
    recur(0, 0, N);
}
