//
//  1074.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/19/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, r, c, ans;

void Z(int y, int x, int size) {
    if (y == r && x == c) {
        cout << ans; exit(0);
    }
    
    if (y + size > r && x + size > c && y <= r && x <= c) {
        Z(y, x, size/2);
        Z(y, x + size/2, size/2);
        Z(y + size/2, x, size/2);
        Z(y+size/2, x+size/2, size/2);
    } else {
        ans = size * size + ans;
    }
    
}

int main() {
    cin >> N >> r >> c;
    Z(0, 0, (1 << N));
}
