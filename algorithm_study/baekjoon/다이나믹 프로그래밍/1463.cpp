//
//  1463.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/12/24.
//

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
int N, datas[1000000], a, b, c, tmp;

int main(){
    cin >> N;
    for(int i = 2; i <=N; i++){
        if(i % 3 == 0){
            a = datas[i/3];
        }
        else{
            a = INF;
        }
        if(i % 2 == 0){
            b = datas[i/2];
        }
        else{
            b = INF;
        }
        c = datas[i-1];
        tmp = min({a, b, c});
        datas[i] = tmp+1;
    }
    cout << datas[N];
}
