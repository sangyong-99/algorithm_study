//
//  지폐 접기.cpp
//  algorithm_study
//
//  Created by 신상용 on 2/23/25.
//

#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> wallet, vector<int> bill) {
    if ((min(bill[0], bill[1]) > min(wallet[0], wallet[1])) || (max(bill[0], bill[1]) > max(wallet[0], wallet[1]))) {
        return true;
    } return false;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(check(wallet, bill)) {
        if (bill[0] > bill[1]) {
            bill[0] /= 2;
        } else {
            bill[1] /= 2;
        }
        answer++;
    }
    
    return answer;
}
