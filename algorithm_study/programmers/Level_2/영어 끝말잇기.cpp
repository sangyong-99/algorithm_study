//
//  영어 끝말잇기.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 7/13/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> dupliWords;
    char prevLastChar = words[0][words[0].length() - 1];
    dupliWords.push_back(words[0]);
    
    for(int i = 1; i < words.size(); i++) {
        string ss = words[i];
        char currentFirstChar = ss[0];
        if (prevLastChar == currentFirstChar && find(dupliWords.begin(), dupliWords.end(), ss) == dupliWords.end()) {
            prevLastChar = ss[ss.length() - 1];
            dupliWords.push_back(ss);
            continue;
        } else { // 실패...
            cout << words[i] << endl;
            cout << i;
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

int main() {
    int n = 3;
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    vector<int> answer = solution(n, words);
    for(int i: answer) {
        cout << i << " ";
    }
}
