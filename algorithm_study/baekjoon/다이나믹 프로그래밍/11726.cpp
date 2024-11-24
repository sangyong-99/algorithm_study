//
//  11726.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/24/24.
//

#include <bits/stdc++.h>
using namespace std;

int n;
int datas[1010];

int main() {
    cin >> n;
    datas[1] = 1;
    datas[2] = 2;
    for(int i = 3; i < 1001; i++) {
        datas[i] = (datas[i - 1] + datas[i - 2]) % 10007;
    }
    cout << datas[n];
}
