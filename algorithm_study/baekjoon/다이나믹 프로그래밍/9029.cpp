//
//  main.cpp
//  cube
//
//  Created by 신상용 on 2022/10/06.
//



#include <bits/stdc++.h>
using namespace std;
ifstream fin("cube.inp");
ofstream fout("cube.out");
int datas[201][201][201] = {0, };
int T, W, L, H, ret, temp;

void input_data(){
    for(int i = 1; i <= 200; i++){
        for(int j = 1; j <= 200; j++){
            for(int z = 1; z <= 200; z++){
                if(!datas[i][j][z]){
                    if(i == 1 || j == 1 || z == 1){
                        datas[i][j][z] = i * j * z; continue;
                    }
                    else if (i % j == 0 && i % z == 0) {
                        datas[i][j][z] = datas[i][z][j] = datas[j][i][z] = datas[j][z][i] = datas[z][i][j] = datas[z][j][i] = (j / i) * (z / i); continue;
                    }
                    else{
                        int ret = 10000000;
                        for (int a = 1; a <= i / 2; a++)
                            ret = min(ret, datas[a][j][z] + datas[i - a][j][z]);
                        for (int b = 1; b <= j / 2; b++)
                            ret = min(ret, datas[i][b][z] + datas[i][j - b][z]);
                        for (int c = 1; c <= z / 2; c++)
                            ret = min(ret, datas[i][j][c] + datas[i][j][z - c]);
                        datas[i][j][z] = datas[i][z][j] = datas[j][i][z] = datas[j][z][i] = datas[z][i][j] = datas[z][j][i] = ret;
                    }
                }
            }
        }
    }
}


int main(){
    fin >> T;
    input_data();
    for(int i = 0; i < T; i++){
        fin >> W >> L >> H;
        fout << datas[W][L][H] << '\n';
    }
}
