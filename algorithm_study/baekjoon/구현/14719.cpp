//
//  14719.cpp
//  Test
//
//  Created by 신상용 on 2022/11/22.
//

#include <bits/stdc++.h>
using namespace std;

int H, W, max_left, max_right, result;
int arrays[600];

int main(){
    cin >> H >> W;
    for(int i = 0; i < W; i++){
        cin >> arrays[i];
    }
    for(int i = 1; i < W-1; i++){
        max_left = 0; max_right = 0;
        for(int j = 0; j < i; j++)
            max_left = max(max_left, arrays[j]);
        for(int j = i+1; j <= W - 1; j++)
            max_right = max(max_right, arrays[j]);
        if((min(max_left, max_right) - arrays[i]) > 0)
            result += (min(max_left, max_right) - arrays[i]);
    }
    cout << result;
}
