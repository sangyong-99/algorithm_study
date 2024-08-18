//
//  1629.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/18/24.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, C;

ll expo(ll B) {
    if (B == 1) {return A % C;}
    ll val = expo(B / 2);
    val = val * val % C;
    if (B % 2 == 0) {return val;}
    return val * A % C;
}

int main() {
    cin >> A >> B >> C;
    cout << expo(B);
}
