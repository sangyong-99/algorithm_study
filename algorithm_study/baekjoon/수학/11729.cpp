//
//  11729.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/19/24.
//

#include <bits/stdc++.h>
using namespace std;

int N;

void hanoi(int n, int start, int end) {
    if (n == 1) { cout << start << " " << end << '\n'; return; }
    hanoi(n - 1, start, 6-start-end);
    cout << start << " " << end << '\n';
    hanoi(n - 1, 6-start-end, end);
}

int main() {
    cin >> N;
    cout << (1<<N) - 1 << '\n';
    hanoi(N, 1, 3);
}
