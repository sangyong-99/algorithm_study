//
//  2164.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/29.
//

#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> qu;

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        qu.push(i);
    }
    while (qu.size() != 1) {
        qu.pop();
        qu.push(qu.front());
        qu.pop();
    }
    cout << qu.front();
}
