//
//  k진수에서 소수 개수 구하기.cpp
//  algorithm_study
//
//  Created by 신상용 on 10/4/24.
//

#include <bits/stdc++.h>
using namespace std;

string datas;

void parse_k(int n, int k) {
    while(n != 0) {
        datas += to_string(n % k);
        n /= k;
    }
    reverse(datas.begin(), datas.end());
}

bool checkPrime(long long n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution2() {
    int answer = 0;
    string str = "";
    for (char c: datas) {
        if (c == '0') {
            if (str.length() == 0) continue;
            if (checkPrime(stol(str))) {
                answer++;
            }
            str = "";
        } else {
            str += c;
        }
    }
    
    if (str.length() != 0) {
        if (checkPrime(stol(str))) {
            answer++;
        }
    }
    
    
    return answer;
}

int solution(int n, int k) {
    int answer = 0;
    parse_k(n, k);
    answer = solution2();
    return answer;
}

int main () {
//    cout << solution(437674, 3);
    cout << solution(110011, 10);
}
