//
//  1212.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/30.
//

#include <bits/stdc++.h>
using namespace std;

string eight;
string two[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
int temp;

int main(){
    cin >> eight;
    
    for(int i = 0; i < eight.length(); i++){
        temp = eight[i] - '0';
        if (i == 0) cout << stoi(two[temp]);
        else cout << two[temp];
    }
}
