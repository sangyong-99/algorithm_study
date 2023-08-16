//
//  2504.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/08/16.
//

#include <bits/stdc++.h>
using namespace std;

stack<int> data_stack;
string ss; int temp;

int main() {
    cin >> ss;
    for(int i = 0; i < ss.length(); i++) {
        switch (ss[i]) {
            case '(':
                data_stack.push(-1);
                break;
            case '[':
                data_stack.push(-2);
                break;
            case ')':
                if (data_stack.size() > 0 && data_stack.top() == -1) {
                    data_stack.pop();
                    data_stack.push(2); // 하나 삭제하고 2 삽입
                } else if (data_stack.size() > 0 && data_stack.top() > 0) {
                    temp = data_stack.top(); data_stack.pop();
                    if (data_stack.size() > 0 && data_stack.top() == -1) {
                        data_stack.pop(); data_stack.push(2 * temp);
                    } else {    // 예외 처리
                        cout << 0; return 0;
                    }
                } else {
                    cout << 0; return 0;
                }
                break;
            case ']':
                if (data_stack.size() > 0 && data_stack.top() == -2) {
                    data_stack.pop();
                    data_stack.push(3); // 하나 삭제하고 2 삽입
                } else if (data_stack.size() > 0 && data_stack.top() > 0) {
                    temp = data_stack.top(); data_stack.pop();
                    if (data_stack.size() > 0 && data_stack.top() == -2) {
                        data_stack.pop(); data_stack.push(3 * temp);
                    } else {    // 예외 처리
                        cout << 0; return 0;
                    }
                } else {
                    cout << 0; return 0;
                }
                
                break;
            default:
                break;
            
        }
        if(data_stack.top() > 0 && data_stack.size() >= 2) {
            temp = data_stack.top();
            data_stack.pop();
            if (data_stack.top() > 0) {
                temp += data_stack.top();
                data_stack.pop();
                data_stack.push(temp);
            } else {
                data_stack.push(temp);
            }
        }
    }
    if (data_stack.size() != 1) {
        cout << 0;
        return 0;
    } else if (data_stack.top() < 0) {
        cout << 0;
        return 0;
    } else {
        cout << data_stack.top();
        
    }
}
