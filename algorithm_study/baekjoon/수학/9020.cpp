//
//  9020.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/09/01.
//

#include <bits/stdc++.h>
using namespace std;

int T, N, result;


int main(){
    cin >> T;
    for(int z = 0; z < T; z++){
        cin >> N;
        int data[N + 1];
        fill_n(data, N+1, 1);   //data N인덱스까지 0으로 초기화
        data[0] = 0; data[1] = 0;
        for(int i = 2; i <= N / 2; i++){    //i를 N까지 순회
            for(int j = 2; j*i <= N; j++){
                
                data[i*j] = 0;
            }
        }
        for(int q = 0; q < N / 2; q++){
            if(data[N / 2 - q] == 1 && data[N / 2 + q] == 1){
                result = (N / 2 - q) + (N / 2 + q);
                if(result == N){
                    cout << (N / 2 - q) << ' ' << (N / 2 + q) << '\n';
                    break;
                }
            }
            
        }
    }
}
