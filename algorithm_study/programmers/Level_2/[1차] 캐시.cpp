//
//  [1차] 캐시.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 9/10/24.
//

#include <bits/stdc++.h>

using namespace std;

string lowers(string s) {
    string temp;
    for(char c: s) {
        if ('A' <= c && 'Z' >= c) {
            c += 32;
        }
        temp += c;
    }
    return temp;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;

    if (cacheSize == 0) {
        return cities.size() * 5;
    }

    for(string ss: cities) {
        string s = lowers(ss);
        if (find(cache.begin(), cache.end(), s) == cache.end()) {
            if (cache.size() >= cacheSize) {
                cache.pop_front();
            }
            answer += 5;
            cache.push_back(s);
        }else {
            int indexs = find(cache.begin(), cache.end(), s) - cache.begin();
            cache.erase(cache.begin() + indexs);
            cache.push_back(s);
            answer += 1;
        }
    }
    return answer;
}
