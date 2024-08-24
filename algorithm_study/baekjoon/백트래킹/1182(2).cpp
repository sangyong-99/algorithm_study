//
//  1182(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 8/24/24.
//

#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;

void func(int k, int total) {
    if (k == n) {
        if (total == s) cnt++;
        return;
    }
    
    func(k + 1, total);
    func(k + 1, total + arr[k]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    func(0, 0);
    if (s == 0) cnt--;
    cout << cnt;
}
