//
//  main.cpp
//  Card Game(15)
//
//  Created by 신상용 on 2022/10/26.
//

#include <bits/stdc++.h>
using namespace std;
ifstream fin("card.inp");
ofstream fout("card.out");
int T, N, card[1000], dp[1000][1000][2];

int input_data(int i, int j, bool alice){
    int &dkdk = dp[i][j][alice];
    if(dkdk != -1) return dkdk;
    if(i == j){
        if(alice)
            return dkdk = card[i];
        return dkdk = 0;
    }
    if(alice)
        return dkdk = max(input_data(i+1,j,0)+card[i],input_data(i,j-1,0)+card[j]);
    return dkdk = min(input_data(i+1,j,1),input_data(i,j-1,1));
}

int main(){
    fin >> T;
    for(int zz = 0; zz < T; zz++){
        memset(dp,-1,sizeof(dp));
        fin >> N;
        for (int i = 0; i < N; i++)
            fin >> card[i];
        fout << input_data(0, N - 1, 1) << '\n';
    }
}
