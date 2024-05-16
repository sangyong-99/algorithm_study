//
//  1406(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 5/16/24.
//

#include <bits/stdc++.h>
using namespace std;

list<char> s;
char c;
int T;
string ss;
int main() {
    getline(cin, ss);
    for(int i = 0; i < ss.size(); i++) {
        s.push_back(ss[i]);
    }
    cin >> T;
    auto iterators = s.end();
    while (T--) {
        cin >> ss;
        if (ss == "L") {
            if (iterators != s.begin()) {
                iterators--;
            }
        } else if (ss == "D") {
            if (iterators != s.end()) {
                iterators++;
            }
        } else if (ss == "B") {
            if (!s.empty() && iterators != s.begin()) {
                iterators = s.erase(--iterators);
            }
        } else if (ss == "P") {
            cin >> c;
            s.insert(iterators, c);
        }
    }
    
    // list s 출력
    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it;
    }
    
}
