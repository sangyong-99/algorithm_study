//
//  1475.cpp
//  algorithm_study
//
//  Created by 신상용 on 5/29/24.
//

#include <bits/stdc++.h>

using namespace std;
string N;
vector<int> a(10);
int main() {
    cin >> N;
    for(char c: N) {
        a[c-'0']++;
    }
    a[6] = ceil(double(a[6] + a[9]) / 2);
    a[9] = a[6];
    cout << *max_element(a.begin(), a.end());
    
}
