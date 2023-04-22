//
//  2581.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/08/29.
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
            if(option){mins = i; option = 0;}
            sum += i;
        }
    }
    if(sum == 0) {cout << -1 << '\n'; return 0;}
    cout << sum << '\n' << mins << '\n';
    return 0;
}


/*
 예제 입력 1  복사
 60
 100
 예제 출력 1  복사
 620
 61
 예제 입력 2  복사
 64
 65
 예제 출력 2  복사
 -1
 */
