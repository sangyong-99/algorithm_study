//
//  20053.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/30.
//

#include <bits/stdc++.h>
using namespace std;

int T, N, maxss, minss, datas;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        maxss = -1000000;
        minss = 1000000;
        
        for(int j = 0; j < N; j++){
            cin >> datas;
            if (maxss < datas){
                maxss = datas;
            }
            if (minss > datas){
                minss = datas;
            }
        }
        cout << minss << " " << maxss << '\n';
    }
}
