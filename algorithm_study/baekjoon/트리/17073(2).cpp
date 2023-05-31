//
//  17073(2).cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/30.
//

#include <bits/stdc++.h>
using namespace std;

int N, W, U, V, countss;
vector<int> arr_data[500010];

int main(){
    cin >> N >> W;
    for (int i = 0; i < N - 1; i++){
        cin >> U >> V;
        arr_data[U].push_back(V);
        arr_data[V].push_back(U);
    }
    for(int j = 2; j <= N; j++){
        if(arr_data[j].size() == 1){
            countss++;
        }
    }
    cout << fixed;
    cout.precision(5);
    cout << (double)W / countss;
}
