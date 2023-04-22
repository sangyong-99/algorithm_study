//
//  1978.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/08/29.
//

#include <bits/stdc++.h>
using namespace std;

int N, cnt;

int main(){
    cin >> N;
    int data[N];
    for(int i = 0; i < N; i++){
        cin >> data[i];
    }
    for(int i = 0; i < N; i++){
        if(data[i] == 1){cnt--;}
        for(int j = 2; j < data[i]; j++){
            
            if(data[i] % j == 0) {cnt--; break; }
        }
        cnt++;
    }
    cout << cnt << '\n';
}
