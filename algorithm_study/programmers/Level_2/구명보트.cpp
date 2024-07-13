//
//  구명조끼.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/13/24.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int l = 0, r = people.size() - 1;
    while(l <= r) {
        if (people[l] + people[r] <= limit) {l++; r--;}
        else r--;
        answer++;
    }
    return answer;
}
