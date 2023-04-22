//
//  10799.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/02.
//

#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> char_stack;
int results = 0;

int main(){
    getline(cin, str);
    for(int i = 0; i < str.length(); i++){
        if (str[i] == '('){
            char_stack.push('(');
        }
        else if (str[i] == ')'){
            if (str[i-1] == '('){
                char_stack.pop();
                results += char_stack.size();
            }
            else if (str[i-1] == ')'){
                char_stack.pop();
                results += 1;
            }
        }
    }
    cout << results << '\n';
}
