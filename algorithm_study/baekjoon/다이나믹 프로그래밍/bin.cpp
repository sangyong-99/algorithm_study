//
//  main.cpp
//  Recycling Bins
//
//  Created by 신상용 on 2022/11/03.
//

#include <bits/stdc++.h>
#define MAX 10000000000000;
using namespace std;
ifstream fin("bin.inp");
ofstream fout("bin.out");
long long T, n, m, indexss, sums;
long long datas[510];
long long sum[510][510];
long long result[510][510];
void reset(){
    fin >> n >> m;
    for(long long i = 1; i <= n; i++){
        fin >> datas[i];
    }
    sort(datas+1, datas+(n+1));
    memset(result, 1, sizeof(result));
    memset(sum, 0, sizeof(sum));
    
    for(long long i = 0; i < 510; i++){
        for(long long j = 0; j < 510; j++){
            if(j == 0) result[i][j] = 0;
            else result[i][j] = MAX;
        }
    }
}
void solution(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i >= j) sum[i][j] = 0;
            else{
                sums = 0;
                indexss = datas[i+(j - i) / 2];
                for(int k = i; k <= j; k++){
                    sums += abs(datas[k] - indexss);
                }
                sum[i][j] = sums;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= j; k++){
                result[i][j] = min(result[i][j], result[i-1][j-k] + sum[j-k+1][j]);
            }
        }
    }
}
int main() {
    fin >> T;
    for(long long i = 0; i < T; i++){
        reset();
        solution();
        fout << result[m][n] << '\n';
    }
}
