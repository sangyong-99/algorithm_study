//
//  10828.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/03/16.
//

#include <bits/stdc++.h>
using namespace std;
stack<int> ss; int N, value; string option;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> option;
        if (option == "push") {
            cin >> value;
            ss.push(value);
        }
        else if(option == "pop"){
            if (!ss.empty()){
                (value == 1000000) ? cout << -1 << '\n' : cout << ss.top() << '\n';
                ss.pop();
            }
            else cout << -1 << '\n';
        }
        else if(option == "size")
            cout << ss.size() << '\n';
        else if (option == "empty") ss.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
        else
            if (!ss.empty()) (value == 1000000) ? cout << -1 << '\n' : cout << ss.top() << '\n';
            else cout << -1 << '\n';
        
    }
}
