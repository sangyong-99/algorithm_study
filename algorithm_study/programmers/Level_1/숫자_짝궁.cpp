#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long countX[20] = {0, };
long long countY[20] = {0, };
long long results[20] = {0, };

string solution(string X, string Y) {
    string answer = "";
    
    for(char c: X) {
        int temp = c - '0';
        countX[temp]++;
    }
    for(char c: Y) {
        int temp = c - '0';
        countY[temp]++;
    }
    
    for(int i = 0; i < 11; i++) {
        int count = min(countX[i], countY[i]);
        results[i] = count;
    }
    
    
    for(int i = 10; i >= 0; i--) {
        for(int j = 0; j < results[i]; j++) {
            answer += to_string(i);
        }
    }
    if (answer == "") return "-1";
    if (answer[0] == '0') return "0";
    return answer;
}
