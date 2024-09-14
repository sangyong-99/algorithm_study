//
//  전화번호 목록.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/14/24.
//

#include <bits/stdc++.h>
using namespace std;

bool cmp(const string a1, const string a2) {
    if (a1.size() < a2.size()) {
        return true;
    }
    return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, bool> mp;
    
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    for(string phone: phone_book) {
        for(int i = 1; i <= phone.size(); i++) {
            if (mp[phone.substr(0, i)]) {
                return false;
            }
        }
        mp[phone] = true;
    }
    
    
    return answer;
}

int main() {
//    cout << solution({"119", "97674223", "1195524421"});
    cout << solution({"123","456","789"});
//    cout << solution({"12","123","1235","567","88"});
}
