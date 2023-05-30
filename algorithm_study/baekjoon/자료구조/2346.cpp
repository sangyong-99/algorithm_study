//
//  2346.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/29.
//

#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> de;
int N, paper;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> paper;
        de.push_back(make_pair(i, paper));
        
    }
    paper = de.front().second;
    cout << de.front().first << ' ';
    de.pop_front();
    
    while (de.size() > 1) {
        if (paper > 0){
            for(int i = 0; i < paper - 1; i++){
                de.push_back(make_pair(de.front().first, de.front().second));
                de.pop_front();
            }
            paper = de.front().second;
            cout << de.front().first << ' ';
            de.pop_front();
        } else {
            for(int i = 0; i > paper + 1; i--){
                de.push_front(make_pair(de.back().first, de.back().second));
                de.pop_back();
            }
            paper = de.back().second;
            cout << de.back().first << ' ';
            de.pop_back();
            
        }
        
    }
    cout << de.front().first;
}
