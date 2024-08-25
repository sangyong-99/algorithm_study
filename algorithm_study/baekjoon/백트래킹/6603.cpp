//
//  6603.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/25/24.
//

#include <bits/stdc++.h>
using namespace std;

int k;

int main() {
    while (1) {
        cin >> k;
        int arr[k];
        int initarr[k];
        if (k == 0) {return 0;}
        for(int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        
        fill(initarr, initarr+k, 1);
        for(int i = 0; i < 6; i++) {
            initarr[i] = 0;
        }
        
        do {
            for(int i = 0; i < k; i++) {
                if (initarr[i] == 0) {
                    cout << arr[i] << ' ';
                }
            }
            cout << '\n';
        } while (next_permutation(initarr, initarr + k));
        
        cout << '\n';
        
    }
    
}
