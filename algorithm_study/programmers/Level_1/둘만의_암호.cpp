//
//  둘만의_암호.cpp
//  algorithm_study
//
//  Created by 신상용 on 5/12/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int input_datas[30] = {0, };

string solution(string s, string skip, int index) {
    string answer = "";
    for(char c: skip) {
        input_datas[(int)c - 97] = 1;
    }
    
    for(char c: s) {
        int temp = ((int)c - 97);
        int indexs = index;
        
        while(indexs > 0) {
            if (input_datas[(temp + 1) % 26] == 1) {
                indexs++;
            }
            temp++;
            temp %= 26;
            
            indexs--;
        }
        
        char cc = temp + 97;
        answer += cc;
    }
    
    return answer;
}

int main() {
    string s = "yyyyy";
    string skip = "za";
    int index = 2;
    
    cout << solution(s, skip, index);
}
