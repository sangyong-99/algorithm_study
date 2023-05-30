//
//  5597.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/30.
//

#include <bits/stdc++.h>
using namespace std;

bool results[35] = {false, };
int aa;

int main(){
    for(int i = 0; i < 28; i++){
        cin >> aa;
        results[aa] = true;
    }
    
    for(int i = 1; i <= 30; i++){
        if (!results[i]) {
            cout << i << '\n';
        }
    }
}
