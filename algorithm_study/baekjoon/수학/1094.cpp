//
//  1094.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/2/23.
//

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int X;
    cin >> X;
 
    int ans = 0;
    while (X>0) {
        if (X % 2 == 1) {
            ans++;
        }
        X /= 2;
    }
 
    cout << ans;
 
}
