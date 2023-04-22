//
//  2798.cpp
//  baekjoon
//
//  Created by 신상용 on 2022/09/01.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    int arr[100];
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    int max;
    max = 0;
    for(int i = 0; i < N - 2; i++){
        for(int j = i + 1; j < N - 1; j++){
            for(int k = j + 1; k < N; k++){
                if((arr[i] + arr[j] + arr[k]) > max && (arr[i] + arr[j] + arr[k]) <= M)
                    max = arr[i] + arr[j] + arr[k];
            }
        }
    }
    cout << max;
}
