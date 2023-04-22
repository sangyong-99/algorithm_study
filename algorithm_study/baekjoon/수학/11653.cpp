//
//  11653.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/08/29.
//

#include <bits/stdc++.h>
using namespace std;

int N, i;
vector<int> a;
int main(){
    cin >> N;
    while(true){
        for(i = 2; i <= N; i++){
            if(N%i == 0){
                N /= i;
                a.push_back(i);
                break;
            }
        }
        if(N == 1) break;
    }
    for(int k:a)
        cout << k << '\n';
}
