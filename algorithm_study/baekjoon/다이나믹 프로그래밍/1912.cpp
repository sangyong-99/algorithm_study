//
//  1912.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/11/24.
//

#include <bits/stdc++.h>

using namespace std;

int n, results = -2000, temp, dp = -2000;

void solution() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        dp = max(dp + temp, temp);

        results = max(dp, results);
    }
}

int main() {
    solution();
    cout << results;
}
