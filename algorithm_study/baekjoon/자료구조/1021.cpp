//
//  1021.cpp
//  algorithm_study
//
//  Created by 신상용 on 6/29/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, temp, results;
deque<int> datas;

int main() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        datas.push_back(i);
    }
    
    while (M--) {
        cin >> temp;
        int a1 = find(datas.begin(), datas.end(), temp) - datas.begin();
        int a2 = datas.size() - a1;
        
        if (a1 <= a2) {
            while (a1--) {
                int f = datas.front();
                datas.pop_front();
                datas.push_back(f);
                results++;
            }
        }
        else {
            while (a2--) {
                int b = datas.back();
                datas.pop_back();
                datas.push_front(b);
                results++;
            }
        }
        
        datas.pop_front();
    }
    
    cout << results;
    
}
