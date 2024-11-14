//
//  1860.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/14/24.
//

#include<bits/stdc++.h>

using namespace std;
int N, M, K, temp;
vector<int> timeDate;
bool result = true;

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        timeDate.push_back(temp);
    }
    sort(timeDate.begin(), timeDate.end(), less<int>());
}

void clear() {
    timeDate.clear();
    result = true;
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        clear();
        input();
        for (int i = 0; i < N; i++) {
            temp = timeDate[i] / M * K;
            if (temp < i + 1) {
                result = false;
                break;
            }
        }
        if (result) {
            cout << "#" << test_case << " " << "Possible" << '\n';
        } else {
            cout << "#" << test_case << " " << "Impossible" << '\n';
        }

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
