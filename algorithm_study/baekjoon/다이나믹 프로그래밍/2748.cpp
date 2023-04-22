//
//  2748.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/03/27.
//

#include <bits/stdc++.h>
using namespace std;

int N;
long long datass[100];

int main(){
    datass[0] = 0;
    datass[1] = 1;
    cin >> N;
    for(int i = 2; i <= N; i++) {
        datass[i] = datass[i-1] + datass[i-2];
    }
    
    cout << datass[N];
}
