//
//  1406.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/02.
//

#include <bits/stdc++.h>
using namespace std;

string s;
char ss;
int counts;
stack<char> left_stack, right_stack;

void input_data(){  //데이터 입력받는 부분
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
        left_stack.push(s[i]);
    }
    cin >> counts;
}

int main(){
    input_data();
    for(int i = 0; i < counts; i++){
        cin >> ss;
        if (ss == 'L'){ //L일때
            if(!left_stack.empty()){
                ss = left_stack.top();
                left_stack.pop();
                right_stack.push(ss);
            }
        }
        
        else if (ss == 'D'){    //D일때
            if(!right_stack.empty()) {
                ss = right_stack.top();
                right_stack.pop();
                left_stack.push(ss);
            }
        }
        
        else if (ss == 'B'){    //B일때
            if(!left_stack.empty()){
                left_stack.pop();
            }
        }
        
        else if (ss == 'P'){    //P일때
            cin >> ss;
            left_stack.push(ss);
        }
    }
    while(!left_stack.empty()){ //왼쪽을 오른쪽으로 옮기는 코드
        right_stack.push(left_stack.top());
        left_stack.pop();
    }
    while(!right_stack.empty()){    //오른쪽을 출력하는 코드
        cout << right_stack.top();
        right_stack.pop();
    }
}
