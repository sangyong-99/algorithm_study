//
//  1158.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/23.
//

#include <bits/stdc++.h>
using namespace std;
int N, countss, K; queue<int> qu;

void input_data(){
    cin >> N >> K;
    countss = K - 1;
    for(int i = 1; i <= N; i++){
        qu.push(i);
    }
}

int main(){
    input_data();
    cout << "<";
    while(N != 1) {
        for(int i = 0; i < countss; i++){
            qu.push(qu.front());
            qu.pop();
        }
        cout << qu.front() << ", ";
        qu.pop();
        N--;
    }
    cout << qu.front() << ">";
}
