//
//  2439.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/3/23.
//

#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            if(n - j <= i) cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
}
