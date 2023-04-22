//
//  main.cpp
//  addingways
//
//  Created by 신상용 on 2022/10/26.
//

#include <bits/stdc++.h>
using namespace std;
ifstream fin("addingways.inp");
ofstream fout("addingways.out");
long long datas[25][400][400];
long long ss;
long long standard;
long long sumss = 0;
long long result_1 = 0;
int x = 10;
int y = 10;
void solution2(){
    for(int i = 2; i<= 300;){
        datas[2][i][0] = i/2;
        datas[2][i+1][0] = (i+1)/2;
        i += 2;
    }
}
void solution3(){
    standard = 2;
    for(long long i = 3; i <= 300; i++){  //n
        for(long long j = standard; j <= 300; j++){
            ss = (i - j) - ceil(j / 2.0);
            if(ss >= 0){
                if((ss+1) < datas[2][j][0]){
                    datas[3][i][j] += (ss + 1);
                }
                else{
                    for(long long k = i; k <= 300; k++){
                        datas[3][k][j] = (ss + 1);
                    }
                    standard++;
                }
            }
            else break;
        }
    }
}
void solution4(){
    for(long long k = 4; k <= 20; k++){         //k값은 순회되는 k값
        standard = (k - 1);         // 처음에 전의 개수를 k-1로 둔다.
        for(long long n = k; n <= 300; n++){        //n의 순환
            for(long long j = standard; j <= 300; j++){     // 처음부터 j의 값을 설정한다.
                ss = (n - j) - ceil(j / (k - 1));
                if(ss >= 0){
                    sumss = j - (n - j);
                    if(sumss > 2){
                        result_1 = 0;
                        for(long long zz = sumss; zz <= 300; zz++){
                            result_1 += datas[k-1][j][zz];
                        }
                        datas[k][n][j] = result_1;
                    }
                    else{
                        result_1 = 0;
                        for(long long zz = 1; zz <= 300; zz++){
                            result_1 += datas[k-1][j][zz];
                        }
                        for(long long zz = n; zz <= 300; zz++){
                            datas[k][zz][j] = result_1;
                        }
                        standard++;
                    }
                }
                else break;
            }
        }
    }
}
int main() {
    solution2();
    solution3();
    solution4();
    while(true){
        fin >> x >> y;
        if(x == 0 && y == 0) break;
        else if(y == 1) fout << 1 << '\n';
        else if (x == y) fout << 1 << '\n';
        else if (x < y) fout << 0 << '\n';
        else{
            long long ckck = 0;
            for(int i = 0; i <= 300; i++){
                ckck += datas[y][x][i];
            }
            fout << (ckck % 1000000007) << '\n';
        }
    }
}

