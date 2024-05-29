//
//  5397.cpp
//  algorithm_study
//
//  Created by 신상용 on 5/29/24.
//

#include <bits/stdc++.h>
using namespace std;


int T; string s;
int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> T;
    cin.ignore();
    while(T--) {
        list<char> l;
        auto iterator = l.begin();
        
        getline(cin, s);
        for(char c: s) {
            if (c == '<') {
                if (iterator != l.begin()) {
                    iterator--;
                }
            }
            else if (c == '>') {
                if (iterator != l.end()) {
                    iterator++;
                }
            }
            else if (c == '-') {
                if (iterator != l.begin()) {
                    iterator = l.erase(--iterator);
                }
            }
            else {
                l.insert(iterator, c);
            }
        }
        for(char c: l) {
            cout << c;
        }
        cout << '\n';
    }
    
    
}
