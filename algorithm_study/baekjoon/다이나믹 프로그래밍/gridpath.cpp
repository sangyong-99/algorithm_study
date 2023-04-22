//
//  main.cpp
//  gridpath
//
//  Created by 신상용 on 2022/09/29.
//

#include <bits/stdc++.h>
using namespace std;
ifstream fin("gridpath.inp");
ofstream fout("gridpath.out");
int N, M;
int cost;
int arr[210][210];      //초기 배열
int costs[210][210];    //비용 계산 배열
vector<string> ss;
void first(){
    costs[0][0] = arr[0][0];        //(0, 0) 삽입
    for(int i = 1; i < N; i++){
        if(arr[i][0] != -1){
            costs[i][0] = arr[i][0] + costs[i-1][0];
        }else break;
    }
    for(int i = 1; i < M; i++){
        if(arr[0][i] != -1){
            costs[0][i] = arr[0][i] + costs[0][i-1];
        }else break;
    }
}
int main() {
    fin >> N; fin >> M;
    fill(costs[0], costs[209], -1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            fin >> arr[i][j];
        }
    }
    first();
    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            if(arr[i][j] == -1){
                costs[i][j] = -1;
            }
            else if(costs[i][j-1] == -1 && costs[i-1][j] == -1)
                costs[i][j] = -1;
            else if(costs[i][j-1] == -1)
                costs[i][j] = arr[i][j] + costs[i-1][j];
            else if(costs[i-1][j] == -1)
                costs[i][j] = arr[i][j] + costs[i][j-1];
            else
                costs[i][j] = arr[i][j] + min(costs[i][j-1], costs[i-1][j]);
        }
    }
    if(costs[N-1][M-1] == -1){
        fout << "No path." <<'\n';
    }
    else{
        fout << costs[N-1][M-1] << '\n';
        
        //우측으로 이동하는 경로를 우선으로
        int r_index, c_index;
        r_index = N-1; c_index = M-1;
        while(r_index >= 0 && c_index >= 0){
            if(costs[r_index][c_index - 1] == costs[r_index][c_index] - arr[r_index][c_index]){
                ss.push_back("(" + to_string(r_index) + " " + to_string(c_index) + ")");
                c_index--;
            }
            else if(costs[r_index-1][c_index] == costs[r_index][c_index] - arr[r_index][c_index]){
                ss.push_back("(" + to_string(r_index) + " " + to_string(c_index) + ")");
                r_index--;
            }
        }
    }
    reverse(ss.begin(), ss.end());
    for(string a: ss){
        fout << a << '\n';
    }
}



