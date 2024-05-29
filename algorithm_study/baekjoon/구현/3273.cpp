//
//  3273.cpp
//  algorithm_study
//
//  Created by 신상용 on 5/29/24.
//

#include <bits/stdc++.h>
using namespace std;
int n, x, temp, countss;
vector<int> datas;
vector<int> results(2000010);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> temp;
        datas.push_back(temp);
    }
    
    cin >> x;
    
    for(int i = 0; i < datas.size(); i++) {
        temp = datas[i];
        if ((x - temp) >0 && results[x - temp] == 1) {
            countss++;
        }
        results[temp] = 1;
    }
    cout << countss;
}
