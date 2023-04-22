//
//  1052.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/12/27.
//

#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(){
    cin >> N >> K;
    
    if(K >= N){
        cout << 0;
    }
    else {
        int answer = 0;

        while (1) {
            int cnt = 0;
            int temp = N;
            while (temp > 0) {
                if (temp % 2 == 0) {
                    temp /= 2;
                }
                else {
                    temp /= 2;
                    cnt++;
                }

            }
                
            if (K >= cnt) {
                break;
            }

            N++;
            answer++;
        }
        cout << answer;
    }
        
    return 0;
}
