//
//  prac.cpp
//  algorithm_study
//
//  Created by 신상용 on 5/12/24.
//

#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for(int x : ingredient){
        if(v.back() == 1 && x == 2) v.back() = 12;
        else if(v.back() == 12 && x == 3) v.back() = 123;
        else if(v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }

    return answer;
}

int main() {
    vector<int> ingredient = {2, 1, 1, 2, 3, 1, 2, 3, 1};
    cout << solution(ingredient);
}
