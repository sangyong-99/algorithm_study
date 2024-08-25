//
//  1759.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/25/24.
//

#include <bits/stdc++.h>
using namespace::std;

int L, C;
char vowels[5]{'a', 'e', 'i', 'o', 'u'};

int main() {
    cin >> L >> C;
    char arr[C];
    for(int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+C);
    int initArr[C];
    fill(initArr, initArr + C, 1);
    
    for(int i = 0; i < L; i++) {
        initArr[i] = 0;
    }
    
    do {
        string s;
        for(int i = 0; i < C; i++) {
            if (initArr[i] == 0) {
                s += arr[i];
            }
        }
        // find 추가
        int vowelCount = 0;
        for(char vowel: vowels) {
            if (s.find(vowel) != string::npos) vowelCount++;
        }
        
        if (vowelCount >= 1 && vowelCount <= (L - 2)) {
            cout << s << '\n';
        }
        
    } while (next_permutation(initArr, initArr+C));
    
}


