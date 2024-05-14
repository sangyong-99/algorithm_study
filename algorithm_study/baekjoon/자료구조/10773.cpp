//
//  10773.cpp
//  algorithm_study
//
//  Created by 신상용 on 5/14/24.
//

#include <bits/stdc++.h>

using namespace std;
int T, temp;
stack<int> ss;
int main() {
    cin >> T;
    while(T--) {
        cin >> temp;
        if (temp == 0) {
            ss.pop();
        } else {
            ss.push(temp);
        }
    }
    int sum = 0;
    while (ss.size() > 0) {
        sum += ss.top();
        ss.pop();
    }
    cout << sum << '\n';
}
