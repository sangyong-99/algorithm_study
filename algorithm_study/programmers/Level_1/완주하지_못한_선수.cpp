#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> um;
    for(string s : participant) {
        if (um.find(s) == um.end()) {
            um.insert(make_pair(s, 1));
        } else {
            um[s]++;
        }
    }
    
    
    for(string s: completion) {
        if (um[s] > 1) {
            um[s]--;
        } else {
            um.erase(um.find(s));
        }
    
    }
    
    answer = um.begin()->first;
    
    return answer;
}
