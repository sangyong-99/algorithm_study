//
//  1228.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/16/24.
//

#include<bits/stdc++.h>

using namespace std;

vector<int> datas, tempDatas;
int N, counts, x, y, s, temp;
string option;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        datas.push_back(temp);
    }
    cin >> counts;
}

void clear() {
    datas.clear();
}

int main(int argc, char **argv) {
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case) {
        clear();
        input();
        for (int i = 0; i < counts; i++) {
            tempDatas.clear();
            cin >> option;
            cin >> x >> y;
            for (int j = 0; j < y; j++) {
                cin >> temp;
                tempDatas.push_back(temp);
            }
            auto it = datas.begin() + x;
            datas.insert(it, tempDatas.begin(), tempDatas.end());
        }
        cout << "#" << test_case << " ";
        for (int i = 0; i < 10; i++) {
            cout << datas[i] << " ";
        }
        cout << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
