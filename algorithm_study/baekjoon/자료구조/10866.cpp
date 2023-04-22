//
//  10866.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/03/18.
//

#include <bits/stdc++.h>
using namespace std;
deque<int> ss; int N, value; string option;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> option;
        if (option == "push_front") {
            cin >> value;
            ss.push_front(value);
        }
        if (option == "push_back") {
            cin >> value;
            ss.push_back(value);
        }
        else if(option == "pop_front"){
            if (!ss.empty()){
                cout << ss.front() << '\n';
                ss.pop_front();
            }
            else cout << -1 << '\n';
        }

        else if(option == "pop_back"){
            if (!ss.empty()){
                cout << ss.back() << '\n';
                ss.pop_back();
            }
            else cout << -1 << '\n';
        }
        
        else if(option == "size") cout << ss.size() << '\n';
        else if (option == "empty") ss.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
        else if (option =="front"){
            ss.empty() ? cout << -1 << '\n' : cout << ss.front() << '\n';
        }
        else if(option =="back")
            ss.empty() ? cout << -1 << '\n' : cout << ss.back() << '\n';
        
    }
}
