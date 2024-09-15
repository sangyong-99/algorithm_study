//
//  [3차] n진수 게임.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/15/24.
//

#include <bits/stdc++.h>
using namespace std;

string jinsu(int n, int num) {
    string al[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
    string trans = "";
    if (num == 0) {trans += "0";}
    while(num != 0) {
        trans += al[num % n];
        num /= n;
    }
    reverse(trans.begin(), trans.end());
    return trans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string numbers = "";
    
    for(int num = 0; num < t * m; num++) {
        numbers += jinsu(n, num);
    }
    
    int order = p - 1;
    int counts = 0;
    for(int i = 0; i < t; i++) {
        answer += numbers[m * i + order];
    }
    
    return answer;
}

int main() {
//    solution(2, 4, 2, 1);
    solution(16, 16, 2, 1);
}
