//
//  2493.cpp
//  algorithm_study
//
//  Created by 신상용 on 5/14/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, temp, countss = 0;
stack<int> ss;
vector<int> datas(500010);
vector<int> results(500010);

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        datas[i] = temp;
    }
    
    for(int i = N - 1; i >= 0; i--) {
        while (!ss.empty()) {
            if (datas[i] >= datas[ss.top()]) {
                results[ss.top()] = i + 1;
                ss.pop();
            }
            else break;
        }
        
        ss.push(i);
    }
    
    
    for (int i = 0; i < N; i++) {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}
