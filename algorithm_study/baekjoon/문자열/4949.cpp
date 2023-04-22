//
//  4949.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/01.
//

#include <bits/stdc++.h>
using namespace std;

vector<string> str;
stack<char> stack_str;
string s;

void input_data(){
    
    while(s != "."){
        getline(cin, s);
        if (s != "."){
            str.push_back(s);
        }
    }
}

int main(){
    input_data();
    for(int i = 0; i < str.size(); i++){
        s = str[i];
        while( !stack_str.empty() ) stack_str.pop();
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '('){
                stack_str.push(')');
            }
            else if (s[j] == '['){
                stack_str.push(']');
            }
            
            else if(s[j] == ')' || s[j] == ']'){
                if(stack_str.empty()){
                    cout << "no" << '\n';
                    goto nono;
                }
                else if (s[j] == stack_str.top()){
                    stack_str.pop();
                }
                else {
                    cout << "no" << '\n';
                    goto nono;
                }
            }
        }
        if(stack_str.empty()){
            cout << "yes" << '\n';
        }
        else cout << "no" <<'\n';
        nono:;
    }
}
