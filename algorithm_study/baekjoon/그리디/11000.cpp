//
//  11000.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/06/13.
//

#include <bits/stdc++.h>
using namespace std;

int N, countss;
int startss, endss, end_time, correctss;
deque<pair<int, int>> vv;

int array_data[200010];


int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> startss >> endss;
        vv.push_back(make_pair(startss, endss));
        
    }
    sort(vv.begin(), vv.end());
    cout << vv.front().first;
    
    vv.pop_front();
    cout << "d";
}
