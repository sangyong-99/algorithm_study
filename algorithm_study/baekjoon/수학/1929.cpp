//
//  1929.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/08/30.
//

#include <bits/stdc++.h>
using namespace std;

int M, N, sum, mins, option = 1;

int main(){
    cin >> M >> N;
    int data[N + 1];
    fill_n(data, N+1, 1);   //data N인덱스까지 0으로 초기화
    data[0] = 0; data[1] = 0;
    for(int i = 2; i <= N / 2; i++){    //i를 N까지 순회
        for(int j = 2; j*i <= N; j++){
            
            data[i*j] = 0;
        }
    }
    
    for(int i = M; i <= N; i++){
        if(data[i]){
            if(option){cout << i << '\n';}
        }
    }
    
    return 0;
}
