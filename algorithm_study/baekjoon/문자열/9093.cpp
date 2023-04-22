//
//  9093.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/03/18.
//

#include <bits/stdc++.h>
using namespace std;
int T, aa; vector<string> x;
string stringBuffer, value;
string str;
int main(){
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; i++){
        getline(cin, str);
        istringstream ss(str);
        while(getline(ss, stringBuffer, ' '))
            x.push_back(stringBuffer);
        for(int j = 0; j < x.size(); j++){
            value = x[j];
            for(int z = value.length() - 1; z >= 0; z-- )
                cout << value[z];
            cout << " ";
        }
        cout << '\n';
        x.clear();
    }
}


