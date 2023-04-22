//
//  main.cpp
//  Driving_License
//
//  Created by 신상용 on 2022/11/10.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ifstream fin("drive.inp");
ofstream fout("drive.out");
const ll INF = 100000000;
ll T, M, N, L, G, result, dp[150][150][250][2], right_data[150][150], down_data[150][150];
void input_data(){
    fin >> M >> N >> L >> G;    result = 0;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N - 1; j++)
            fin >> right_data[i][j];
    for(int i = 0; i < M - 1; i++)
        for(int j = 0; j < N; j++)
            fin >> down_data[i][j];
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < 250; k++)
                for(int l = 0; l < 2; l++)
                    dp[i][j][k][l] = INF;
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
}
void solution(){
    for(int i = 1; i < M; i++)
        dp[i][0][0][1] = dp[i-1][0][0][1] + down_data[i-1][0];
    for(int j = 1; j < N; j++)
        dp[0][j][0][0] = dp[0][j - 1][0][0] + right_data[0][j-1];
    for(int i = 1; i < M; i++)
        for(int j = 1; j < N; j++)
            for(int k = 1; k < 250; k++){
                dp[i][j][k][0] = min(dp[i][j - 1][k][0] + right_data[i][j - 1], dp[i][j - 1][k - 1][1] + right_data[i][j - 1]);
                dp[i][j][k][1] = min(dp[i - 1][j][k][1] + down_data[i - 1][j], dp[i - 1][j][k - 1][0] + down_data[i - 1][j]);
            }
    for(int k = 0; k < 250; k++)
        if(dp[M - 1][N - 1][k][0] <= G || dp[M - 1][N - 1][k][1] <= G){
            result = L * (M + N - 2) + k;
            break;
        }
    result ? fout << result << '\n' : fout << "-1\n";
}
int main() {
    fin >> T;
    for(int z = 0; z < T; z++){
        input_data();
        solution();
    }
}
