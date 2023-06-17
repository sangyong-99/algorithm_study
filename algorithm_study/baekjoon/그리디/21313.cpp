//
//  21313.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/06/13.
//

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vv;

int main() {
    cin >> N;
    if(N % 2 == 0){
        for(int i = 0; i < N/2; i++) {
            vv.push_back(1);
            vv.push_back(2);
        }
    }
    else {
        for(int i = 0; i < N / 2; i++) {
            vv.push_back(1);
            vv.push_back(2);
        }
        vv.push_back(3);
    }
    
    for(int i = 0; i < N; i++) {
        cout << vv[i] << " ";
    }
    
}
