//
//  main.cpp
//  coin
//
//  Created by 신상용 on 2022/09/29.
//

#include <bits/stdc++.h>
using namespace std;
ifstream fin("prac.inp");
ofstream fout("coin.out");

int n, result, re;
int arr[101][101][101];
int d[3]; int dd[3];

void check(int i, int j, int z){
    d[0] = i; d[1] = j; d[2] = z;
    for(int q = 0; q < 3; q++){
        for(int w = 1; w <= 3; w++){
            copy(d, d+3, dd);
            dd[q] = dd[q] - w;
            if(dd[q] >= 0 && arr[dd[0]][dd[1]][dd[2]] == 0){
                arr[i][j][z] = 1;
                return;
            }
        }
    }
    arr[i][j][z] = 0;
    return;
}

void input_data(){
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            for(int z = 0; z <= 100; z++){
                if(arr[i][j][z] == -1){
                    check(i, j, z);
                }
            }
        }
    }
}

void reset(){
    for(int i = 0; i<101; i++){
        for(int j = 0; j<101;j++){
            for(int z = 0; z<101; z++){
                arr[i][j][z] = -1;
            }
        }
    }
    arr[0][0][0] = 0; arr[1][0][0] = 0; arr[0][1][0] = 0; arr[0][0][1] = 0;
    arr[1][1][0] = 1; arr[1][0][1] = 1; arr[0][1][1] = 1; arr[1][1][1] = 0;
}

int main() {
    reset();
    input_data();
    
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> d[0] >> d[1] >> d[2];        //데이터 파일에서 읽어오기
        if(arr[d[0]][d[1]][d[2]] == 0){
            fout << "(" << d[0] << " " << d[1] << " " << d[2] << ") : "<<-1 << '\n';
        }
        else{
            fout << "(" << d[0] << " " << d[1] << " " << d[2] << ") : "<< 1 << '\n';
        }
        
        
        
        
        
        
        
    }
}
