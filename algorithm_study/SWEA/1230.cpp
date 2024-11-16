//
//  1230.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/16/24.
//

#include<bits/stdc++.h>

using namespace std;

list<int> datas;
list<int> tempDatas;
int x, y, s, N, M, temp;
char option;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        datas.push_back(temp);
    }
    cin >> M;
}

void clear() {
    datas.clear();
    tempDatas.clear();
}

void inserts() {
    tempDatas.clear();
    cin >> x >> y;
    for (int i = 0; i < y; i++) {
        cin >> temp;
        tempDatas.push_back(temp);
    }
    auto it = datas.begin();
    advance(it, x);
    datas.insert(it, tempDatas.begin(), tempDatas.end());
}

void del() {
    cin >> x >> y;
    auto s = datas.begin();
    advance(s, x);
    auto e = datas.begin();
    advance(e, x + y);
    datas.erase(s, e);
}

void add() {
    tempDatas.clear();
    cin >> y;
    for (int i = 0; i < y; i++) {
        cin >> temp;
        tempDatas.push_back(temp);
    }
    datas.insert(datas.end(), tempDatas.begin(), tempDatas.end());
}

int main(int argc, char **argv) {
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case) {
        clear();
        input();
        for (int i = 0; i < M; i++) {
            cin >> option;
            switch (option) {
                case 'I':
                    inserts();
                    break;
                case 'D':
                    del();
                    break;
                case 'A':
                    add();
                    break;
            }
        }
        cout << "#" << test_case << " ";
        auto it = datas.begin();
        for(int i = 0; i < 10; i++) {
            cout << *it << " ";
            it++;
        }
        cout << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
