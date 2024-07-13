//
//  N개의 최소공배수.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/13/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, (a % b));
}

int lcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    int k = gcd(a, b);
    return (a*b) / k;
}

int solution(vector<int> arr) {
    int answer;
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        temp = lcd(temp, arr[i]);
    }
    
    return temp;
}
