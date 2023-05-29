//
//  9012.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/29.
//

#include <bits/stdc++.h>
using namespace std;

int T;
stack<int> datas;
string str_data;
bool a = false;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> str_data;
        a = false;
        while( !datas.empty() ) datas.pop();
        for (int j = 0; j < str_data.length(); j++){
            if (str_data[j] == '('){
                datas.push(1);
            } else if (str_data[j] == ')'){
                if (!datas.empty()){
                    datas.pop();
                } else {
                    cout << "NO" << '\n';
                    a = true;
                    break;
                }
            }
        }
        if (a){
            ;
        } else {
            if (datas.empty()){
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}
