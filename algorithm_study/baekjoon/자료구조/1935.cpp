//
//  1935.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/29.
//

#include <bits/stdc++.h>
using namespace std;

vector<double> operator_stack;
double N, a, b, countss;
string str;
int arr_data[30];

int main(){
    cin >> N;
    cin >> str;
    for(int i = 1; i <= N; i++){
        cin >> arr_data[i];
    }
    for(int i = 0; i < str.length(); i++){
        if (isalpha(str[i])){
            operator_stack.push_back(arr_data[str[i] - 'A' + 1]);
        }
        else {
            b = operator_stack.back();
            operator_stack.pop_back();
            a = operator_stack.back();
            operator_stack.pop_back();
            switch (str[i]) {
                case '*':
                    countss = a * b;
                    break;
                case '/':
                    countss = a / b;
                    break;
                case '+':
                    countss = a + b;
                    break;
                case '-':
                    countss = a - b;
                    break;
                default:
                    break;
            }
            operator_stack.push_back(countss);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << operator_stack[0];
}
