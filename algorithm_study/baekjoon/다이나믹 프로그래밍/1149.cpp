//
//  1149.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/12/24.
//

#include <bits/stdc++.h>
using namespace std;

int N, datas[1010][3], results[1010][3];

void input_data(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> datas[i][j];
        }
    }
}

int main(){
    cin >> N;
    input_data();
    for(int i = 0; i < 3; i++){
        results[1][i] = datas[0][i];
    }
    for(int i = 2; i <= N; i++){
        results[i][0] = min({results[i-1][1], results[i-1][2]}) + datas[i-1][0];
        results[i][1] = min({results[i-1][0], results[i-1][2]}) + datas[i-1][1];
        results[i][2] = min({results[i-1][0], results[i-1][1]}) + datas[i-1][2];
    }
    
    cout << min({results[N][0], results[N][1], results[N][2]});
    
}
