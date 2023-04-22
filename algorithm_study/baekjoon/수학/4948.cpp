//
//  4948.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/08/30.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> datas;
int a = 1, N = 300000, cnt = 0, option = 1, q, w;


int main(){
    while(true){
        cin >> a;
        if(a == 0) break;
        datas.push_back(a);
    }
    int data[N + 1];
    fill_n(data, N+1, 1);   //data N인덱스까지 0으로 초기화
    data[0] = 0; data[1] = 0;
    for(int i = 2; i <= N / 2; i++){    //i를 N까지 순회
        for(int j = 2; j*i <= N; j++){
            
            data[i*j] = 0;
        }
    }
    
    
    for(auto it = datas.begin(); it != datas.end(); it++){
        cnt = 0;
        q = *it; w = q * 2;
        for(int j = q + 1 ; j <= w; j++){
            if(data[j]) cnt ++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}
