//
//  1032.cpp
//  Test
//
//  Created by 신상용 on 2022/11/22.
//

#include <bits/stdc++.h>
using namespace std;

int N;
string str1, str2;
int main() {
    cin >> N;
    cin >> str1;
    for(int i = 0; i < N - 1; i++){
        cin >> str2;
        for(int j = 0; j < str1.length(); j++){
            if(str1[j] != str2[j]){
                str1[j] = '?';
            }
        }
    }
    cout << str1;
}
