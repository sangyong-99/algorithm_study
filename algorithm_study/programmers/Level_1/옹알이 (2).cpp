//
//  옹알이 (2).cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 12/22/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string datas[4] = {"aya", "ye", "woo", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(string ss: babbling) {
        bool isFailed = false; //ss단어가 실패 했다. 변수
        int prevIndex = -1;
        while(!isFailed) {
            bool isFinded = false;
            for(int i = 0; i < 4; i++) {
                if(datas[i] == ss.substr(0, datas[i].length()) && prevIndex != i) {
                    ss = ss.substr(datas[i].length());
                    isFinded = true;
                    prevIndex = i;
                    break;
                }
            }
            if (!isFinded) {
                break;
            }
            if (ss.empty()) {
                answer++;
                break;
            }
        }
    }
    return answer;
}

int main() {
    vector<string> babbling = {"aya", "yee", "u", "maa"};
    vector<string> babbling2 = {"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
    cout << solution(babbling2);
}

//["ayaye", "uuuma", "yeye", "yemawoo", "ayaayaa"]에서 발음할 수 있는 것은 "aya" + "ye" = "ayaye", "ye" + "ma" + "woo" = "yemawoo"로 2개입니다. "yeye"는 같은 발음이 연속되므로 발음할 수 없습니다. 따라서 2를 return합니다.
