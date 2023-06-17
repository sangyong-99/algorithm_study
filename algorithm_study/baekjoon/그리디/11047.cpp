//
//  11047.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/06/13.
//

#include <bits/stdc++.h>
using namespace std;

int N, K, sum = 0, countss = 0;
int array_data[12];

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> array_data[i];
    }
    
    while(K != sum) {
        for(int i = N - 1; i >= 0; i--) {
            if (array_data[i] <= K - sum) {
                sum += array_data[i];
                countss++;
                break;
            }
        }
    }
    cout << countss;
    
}
