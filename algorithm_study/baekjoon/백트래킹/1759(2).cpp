//
//  1759(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 8/25/24.
//

#include <bits/stdc++.h>
using namespace std;

int length, num;
int vowel, conso;
vector<char> password;
vector<char> v;

void func(int start, int cnt) {
    if (cnt == length) {
        vowel = 0;
        conso = 0;
        for(int i = 0; i < password.size(); i++) {
            if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
                vowel++;
            else
                conso++;
        }
        if (vowel >= 1 && conso >= 2) {
            for(int i = 0; i < password.size(); i++) {
                cout << password[i];
            }
            cout << '\n';
        }
        return;
    }
    
    for(int i = start; i < v.size(); i++) {
        password.push_back(v[i]);
        func(i+1, cnt+1);
        password.pop_back();
    }
    return;
}

int main() {
    cin >> length >> num;
    for(int i = 0; i < num; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    func(0, 0);
    return 0;
}
