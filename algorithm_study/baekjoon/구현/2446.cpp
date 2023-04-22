//
//  2446.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/03/16.
//

#include <bits/stdc++.h>
using namespace std;
int N, countss1, countss2;
bool bb;
int main(){
    cin >> N; countss1 = 2*N-1;
    int aa = N;
    while (N != 0){
        for(int i = 0; i < aa-N; i++)
            cout << " ";
        for (int i = 0; i < countss1; i++)
            cout << "*";
        cout << '\n';
        N--; countss1 -= 2;
    }
    N+=2; countss1 += 4;
    while (N != aa+1){
        for(int i = 0; i < aa-N; i++)
            cout << " ";
        for (int i = 0; i < countss1; i++)
            cout << "*";
        cout << '\n';
        N++; countss1 += 2;
    }
}
