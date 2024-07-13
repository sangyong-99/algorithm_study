//
//  귤 고르기.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/13/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

bool compare(const pair<int, int> p1, const pair<int, int> p2) {
    if (p1.y == p2.y) {
        return p1.x > p2.x;
    }
    return p1.y > p2.y;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    for (int i = 0; i < tangerine.size(); i++) {
        if (m.find(tangerine[i]) != m.end()) {
            m[tangerine[i]]++;
        } else {
            m[tangerine[i]] = 1;
        }
    }
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), compare);
    for(int i = 0; i < vec.size(); i++) {
        if (k <= 0) break;
        k -= vec[i].y;
        answer++;
    }
    return answer;
}
