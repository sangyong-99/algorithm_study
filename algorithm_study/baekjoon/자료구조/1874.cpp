//
//  1874.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/03/18.
//

#include <bits/stdc++.h>

using namespace std;
int n, indexss = 0, value, maxss = 0, countss = 0;
vector<int> datas; vector<string> results; stack<int> ss;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        datas.push_back(value);
    }
    while (countss != n) {
        while (datas[countss] > maxss){
            maxss++;
            ss.push(maxss);
            indexss++;
            results.push_back("+");
        }
        if (datas[countss] <= maxss) {
            if(ss.top() != datas[countss]){
                cout << "NO";
                return 0;   //탈출
            }
            ss.pop();
            results.push_back("-");
            countss++;
        }
    }
    for(int i = 0; i < results.size(); i++)
        cout << results[i] << "\n";
}
