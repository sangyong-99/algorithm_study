//
//  17413.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/03/31.
//

#include <bits/stdc++.h>
using namespace std;

stack<char> x;
string s, stringBuffer;
bool b;
int countss;
void stack_print(){
    countss = x.size();
    for(int j = 0; j < countss; j++){
        cout << x.top();
        x.pop();
    }
}

int main(){
    getline(cin, s);
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '<'){           //전에꺼 cout하고 조건 처리
            stack_print();
            b = true;
            cout << s[i];
        }
        else if (s[i] == '>'){
            b = false;
            cout << s[i];
        }
        else if (b){
            cout << s[i];
        }
        else {
            if (s[i] == ' '){
                stack_print();
                cout << s[i];
            }
            else {
                x.push(s[i]);
            }
        }
    }
    stack_print();
    cout << '\n';
    
    return 0;
}
