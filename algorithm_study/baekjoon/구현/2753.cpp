//
//  2753.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/30.
//

#include <bits/stdc++.h>
using namespace std;

int year;


int main(){
    cin >> year;
    if (year % 4 == 0 && (year % 100 != 0) || (year % 400 == 0)){
        cout << 1;
    } else {
        cout << 0;
    }
}
