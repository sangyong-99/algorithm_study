//
//  main.cpp
//  card
//
//  Created by 신상용 on 2022/10/09.
//

#include <bits/stdc++.h>
using namespace std;
ifstream fin("card.inp");
ofstream fout("card.out");
int T, n, arr[1001], datas, data_arr[5][1001], maxss;
void input_data(){
    for(int i = 3; i < n; i++, maxss = -10000000)
        for(int j = 2; j < 5; j++, maxss = -10000000)
            (i < j)?data_arr[j][i] = maxss:(j == 2)?data_arr[j][i] = max(data_arr[3][i - j], data_arr[4][i - j]) + arr[i]:
            data_arr[j][i] = max({data_arr[2][i - j], data_arr[3][i - j], data_arr[4][i - j]}) + arr[i];
}
int main() {
    fin >> T;
    for(int i = 0; i < T; i++){
        fin >> n;
        for(int j = 0; j < n; j++){
            fin >> datas;   arr[j] = datas;
            if(j < 3){data_arr[2][j] = datas;data_arr[3][j] = datas;data_arr[4][j] = datas;}
        }
        input_data();
        fout << max({data_arr[2][n-1], data_arr[3][n-1], data_arr[4][n-1]}) << '\n';
    }
}
